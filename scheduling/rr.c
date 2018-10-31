#include <stdio.h>

void findWaitingtime(int processes[], int n, int wt[], int bt[], int quantum){

    int rem_bt[n], flag, t=0, i;

    // initially remaining time=burst time
    for(i=0;i<n;i++)
        rem_bt[i]=bt[i];
    
    // loop indefinately until each process is finished
    while(1){

        flag=1;
        for(i=0;i<n;i++){

            // check each processes, if remaining time greater than 0 then give it time
            if(rem_bt[i]>0){
                flag=0;

                if(rem_bt[i]>quantum){
                    t+=quantum;
                    rem_bt[i]-=quantum;
                } else{ // if remaining time < quantum then process can be completed
                    t+=rem_bt[i];
                    wt[i]=t-bt[i];  // waiting time is time of completion - time taken to complete
                    rem_bt[i]=0;
                }

            }
        }

        if(flag==1)
            break;
    }

}




void findTAT(int processes[], int n, int wt[], int bt[], int tat[]){
    for(int i=0;i<n;i++)
        tat[i]=wt[i]+bt[i];
    // TAT = bt + wt
}


// driver function
void findAvgTime(int processes[], int n, int bt[], int quantum){
    int wt[n],tat[n];
    float total_wt=0.0, total_tat=0.0;

    findWaitingtime(processes,n,wt,bt,quantum);
    findTAT(processes,n,wt,bt,tat);

    printf("\nProcess\t\tBurst time\t\twaiting time\t\tturnaround time\t\tGantt chart");

    for(int i=0;i<n;i++){
        total_tat+=tat[i];
        total_wt=wt[i];
        printf("\n%d\t\t%d\t\t\t\t%d\t\t%d\t\t\t\t%d-%d",i+1,bt[i],wt[i],tat[i],wt[i],tat[i]);
    }

    printf("\nAverage waiting time:\t%f",total_wt/n);
    printf("\nAverage turnaround time:\t%f\n",total_tat/n);
}   




void main(){
    int processes[]={1,2,3};
    int bt[]={3,4,5};
    int quantum=2, n=sizeof processes/sizeof processes[0];
    findAvgTime(processes,n,bt,quantum);
}