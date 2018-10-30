#include <stdio.h>

void main(){
    int n,tat[20],wt[20],bt[20],i,j,p[20];
    float avg_tat,avg_wt;

    printf("Enter the number of processes:\t");
    scanf("%d",&n);

    printf("Enter the burst time of each process:\t");
    for(i=0;i<n;i++){
        printf("\nP%d:\t",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }

    // calculate waiting time of each process
    wt[0]=0;
    for(i=1;i<n;i++){
        for(j=0;j<n;j++){
            wt[i]+=bt[j];
        }
    }

    // calculate average TAT and WT
    printf("\nProcess\t\tBurst time\t\tWaiting time\t\tTurnaround time\t\tGantt chart");

    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];
        printf("\nP%d\t\t%d\t\t\t\t%d\t\t%d\t\t\t\t%d-%d",i+1,bt[i],wt[i],tat[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time:\t %f",avg_wt/n);
    printf("\nAverage turnaround time:\t %f",avg_tat/n);
}