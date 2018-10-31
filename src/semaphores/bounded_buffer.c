#include <stdio.h>
#include <stdlib.h>

int full=0, empty=10, mutex=1, x=0;

void signal(int *s){
    *s=*s=1;
}

void wait(int *s){
    *s=*s-1;
}

void producer(){
    wait(&mutex);
    signal(&full);
    wait(&empty);

    x++;
    printf("\nProduced item: %d",x-1);
    signal(&mutex);
}


void consumer(){
    wait(&mutex);
    wait(&full);
    signal(&empty);

    x--;
    printf("\nConsumed Item: %d",x+1);

    signal(&mutex);
}


void main(){
    while(1){
        int choice;
        printf("\nPress 1 to produce and 2 to consume\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                if(mutex==1 && empty!=0)
                    producer();
                else 
                    printf("\nBuffer is full");
                break;
            case 2:
                if(mutex==1 && full != 0)
                    consumer();
                else
                    printf("\nBuffer is empty");
                break;
            default: printf("\nInvalid choice\n"); exit(0); break;
        }
    }
}