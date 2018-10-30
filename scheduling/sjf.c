#include <stdio.h>

void main(){
    int n,bt[20],p[20],i,pos,j,temp,wt[20],tat[20],total;
    float avg_wait,avg_tat;
    printf("Enter the number of processes \t");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter burst time for process %d \t",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }

    // sort according to burst time
    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(bt[j]<bt[pos])
                pos=j;
        }
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    // calculate wait time and average
    wt[0]=0;    // because wait time of first is 0
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++){
            wt[i]+=bt[j];
        }
        total+=wt[i];
    }

    avg_wait = (float)total/n;

    
    // print process burst time, wait time, turnaround time and gantt chart
    total=0;
    printf("\nProcess \t Burst time \t Wait time \t Turnaround time \t Gantt chart\n");

    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i]; // TAT = burst time + wait time
        total+=tat[i];
        printf("\np%d\t\t %d\t\t %d\t\t\t%d\t\t%d-%d",p[i],bt[i],wt[i],tat[i],wt[i],tat[i]);    
    }
    printf("\nAverage waiting time: %f",avg_wait);
    printf("\nAverage turnaround time: %f",(float)total/n);
}