#include <stdio.h>
#include <stdbool.h>

struct Semaphore{
    int mutex;
    int rcount;
    int rwait;
    bool wrt;
};



void addR(struct Semaphore *s){
    if(s->mutex==0 && s->rcount==0){
        printf("\nSorry, file open in write mode, new reader added in Queue");
        s->rwait++;
    } else{
        printf("\nReader process added");
        s->rcount++;
        s->mutex--;
    }
    return;
}


void addW(struct Semaphore *s){
    if(s->mutex==1){
        printf("\nWriter added");
        s->mutex--;
        s->wrt=true;
    } else if(s->wrt)
        printf("\nSorry, Writer operational");
    else
        printf("\nSorry, file open in read mode");
    return;
}



void remR(struct Semaphore *s){
    if(s->rcount==0)
        printf("\nNo reader to remove");
    else{
        printf("\nReader removed");
        s->mutex++;
        s->rcount--;
    }
    return;
}


void remW(struct Semaphore *s){
    if(!s->wrt)
        printf("\nNo writer to remove");
    else{
        printf("\nWriter removed");
        s->wrt=0;
        s->mutex++;

        // add queued readers to read
        if(s->rwait!=0){
            s->mutex-=s->rwait;
            s->rcount+=s->rwait;
            s->rwait=0;
            printf("\n%d Waiting readers added",s->rwait);
        }
    }
    return;
}



void main(){
    struct Semaphore s1={1,0,0,false};
    while(1){
        system("cls");
        printf("Options :-\n1.Add Reader.\n2.Add Writer.\n3.Remove Reader.\n4.RemoveWriter.\n5.Exit.\n\n\tChoice : ");
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: addR(&s1); break;
            case 2: addW(&s1); break;
            case 3: remR(&s1); break;
            case 4: remW(&s1); break;
            case 5: printf("\n\tGoodBye!"); return;
            default: printf("\nInvalid Entry!"); continue;
        }
        printf("\n\n<<<<<< Current Status >>>>>>\n\n\tMutex\t\t:\t%d\n\tActiveReaders\
        t:\t%d\n\tWaiting Readers\t:\t%d\n\tWriter Active\t:\t%s\n\n", s1.mutex,
        s1.rcount,s1.rwait, (s1.mutex==0 && s1.rcount==0) ? "YES" : "NO");
        system("pause");
        
    }
}