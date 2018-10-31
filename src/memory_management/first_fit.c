#include <stdio.h>

void main(){
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10];

    for(int i=0;i<10;i++){
        flags[i]=0;
        allocation[i]=-1;
    }

    printf("Enter Number of blocks\n");
    scanf("%d",&bno);
    printf("Enter the size of each block\n");
    for(int i=0;i<bno;i++)
        scanf("%d",bsize+i);
    
    printf("Enter Number of processes\n");
    scanf("%d",&pno);
    printf("Enter the size of each process\n");
    for(int i=0;i<pno;i++)
        scanf("%d",psize+i);

    
    // allocating as per first fit
    for(int i=0;i<pno;i++){
        for(int j=0;j<bno;j++){
            if(flags[j]==0 && bsize[j]>=psize[i]){
                allocation[j]=i;
                flags[j]=1;
                break;
            }
        }
    }

    // display allocation details
    printf("\nBlock number\t\tSize\t\tProcess number\t\tsize\n");
    for(int i=0;i<bno;i++){
        printf("%d\t\t\t%d",i+1,bsize[i]);
        if(flags[i]==1)
            printf("\t\t%d\t\t\t%d\n",allocation[i]+1,psize[allocation[i]]);
        else 
            printf("\t\t\t\tNot allocated\n");
    }
    
    
}