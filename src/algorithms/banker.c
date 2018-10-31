#include <stdio.h>
#include <stdlib.h>

void accept(int A[][10], int N[][10], int W[][10], int M[][10], int *n, int *m){

    int i,j;

    printf("Enter the total number of processes:\t");
    scanf("%d",n);
    printf("\nEnter the total nuber of resources:\t");
    scanf("%d",m);

    for(i=0;i<*n;i++){
        printf("\nProcess P[%d]",i+1);
        for(j=0;j<*m;j++){
            printf("\nAllocation for resource R[%d]:\t",j+1);
            scanf("%d",&A[i][j]);
            printf("\nMaximum for resource R[%d]:\t",j+1);
            scanf("%d",&M[i][j]);
        }
    }


    for(i=0;i<*m;i++){
        printf("\nResource %d:\t",j+1);
        scanf("%d",&W[0][i]);
    }


    for(i=0;i<*n;i++)
        for(j=0;j<*m;j++)
            N[i][j]=M[i][j]-A[i][j];
    

    printf("\nAllocation matrix");
    for(i=0;i<*n;i++){
        printf("\n");
        for(j=0;j<*m;j++){
            
            printf("%d\t",A[i][j]);
        }
    }


    printf("\nAllocation matrix");
    for(i=0;i<*n;i++){
        printf("\n");
        for(j=0;j<*m;j++){
            
            printf("%d\t",M[i][j]);
        }
    }


    printf("\nNeed matrix");
    for(i=0;i<*n;i++){
        printf("\n");
        for(j=0;j<*m;j++){
            
            printf("%d\t",M[i][j]);
        }
    }
    
    printf("\n");
}



int banker(int A[][10], int N[][10], int W[][10], int M[][10], int n, int m){
    int Flag[10], G[1][10], flag=0, pflag=0, a[10], i,j,k,x=0;

    for(i=0;i<n;i++)
        Flag[i]=0;
    
    for(i=0;i<m;i++)
        G[0][i]=W[0][i];

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            if(Flag[i]==0){
                flag=0;
                for(j=0;j<m;j++){
                    if(N[i][j]>G[0][j]){
                        flag=1;
                    }
                }
                if(flag==0 && Flag[i]==0){
                    for(j=0;j<m;j++){
                        G[0][j]+=A[i][j];
                        Flag[i]=1;
                        pflag++;
                        a[x++]=i;
                    }
                }
            }
        }
        if(pflag==n){
            printf("\n\n");
            printf("A safety sequence was detected \n");
            for(i=0;i<n;i++){
                printf("\n%d",a[i]);
            }
            printf("\n");
            return 1;
        }
    }

    printf("\n deadlock occurred \n");
    return 0;

  
}




void main(){
    int A[10][10];
    int M[10][10];
    int N[10][10];
    int W[1][10];
    int n,m;
    printf("\n DEADLOCK AVOIDANCE USING BANKER'S ALGORITHM\n");
    accept(A,N,M,W,&n,&m);
    banker(A,N,W,M,n,m);
}