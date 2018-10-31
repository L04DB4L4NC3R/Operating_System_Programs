#include <stdio.h>

void main(){
    int bno, pno, bsize[10],psize[10], barray[10], parray[10], temp, lowest=99999, i, j, fragment[10];

    printf("Enter Number of blocks\n");
    scanf("%d",&bno);
    printf("Enter the size of each block\n");
    for(i=0;i<bno;i++)
        scanf("%d",bsize+i);
    
    printf("Enter Number of processes\n");
    scanf("%d",&pno);
    printf("Enter the size of each process\n");
    for(i=0;i<pno;i++)
        scanf("%d",psize+i);


    for(i=0;i<pno;i++){
        for(j=0;j<bno;j++){
            if(barray[j]!=1){
                temp=bsize[j]-psize[i];
                if(temp>0 && lowest>temp){
                    parray[i]=j;
                    lowest=temp;
                }
            }
        }
        fragment[i]=lowest;
        barray[parray[i]]=1;
        lowest=99999;
    }

    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for(i=1;i<=pno && parray[i]!=0;i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,psize[i],parray[i],bsize[parray[i]],fragment[i]);
}   