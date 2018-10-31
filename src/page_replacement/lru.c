#include <stdio.h>

int findLRU(int timee[], int n){
    int t=timee[0], pos;
    for(int i=1;i<n;i++){
        if(t>timee[i]){
            t=timee[i];
            pos=i;
        }
    }
    return pos;
}


void main(){
    int fault, counter, i, j, frames[10], pages[10], fno, pno, f1, f2, timee[10], pos;

    printf("\nEnter the number of frames:\t");
    scanf("%d",&fno);
    printf("\nEnter the number of pages:\t");
    scanf("%d",&pno);

    printf("\nENter refrerence string:\t");
    for(i=0;i<pno;i++)
        scanf("%d",&pages[i]);

    // initialize frames
    for(i=0;i<fno;i++)
        frames[i]=-1;
    
    for(i=0;i<pno;i++){
        f1=f2=0;
        for(j=0;j<fno;j++){
            if(frames[j]==pages[i]){
                counter++;
                timee[j]=counter;
                f1=f2=1;
                break;
            }
        }

        if(f1==0){
            for(j=0;j<fno;j++){
                if(frames[j]==-1){
                    counter++;
                    fault++;
                    frames[j]=pages[i];
                    f2=1;
                    break;
                }
            }
        }

        if(f2==0){
            pos = findLRU(timee, fno);
            counter++;
            fault++;
            frames[pos]=pages[i];
            timee[pos]=counter;
        }
        printf("\n");
        for(j=0;j<fno;j++)
            printf("%d\t",frames[j]);
    }
    printf("\nTotal number of page faults:\t%d",fault);

}