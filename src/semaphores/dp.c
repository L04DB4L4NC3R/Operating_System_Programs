/**
 * Dining philosopher's problem using semaphores and pthread
 * **/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4)%5
#define RIGHT (phnum + 1)%5

int state[N], phil[N]={0,1,2,3,4};
sem_t S[N], mutex;



void test(int phnum){
    if(state[phnum]==HUNGRY
       && state[LEFT]!=EATING  
       && state[RIGHT]!=EATING){
           state[phnum]=EATING;
           sleep(2);
           printf("\nPhilosopher %d takes fork %d and %d",phnum+1,LEFT+1,phnum+1);
           printf("\nPhilosopher %d is eating",phnum+1);
           sem_post(&S[phnum]);
       } 
}



void take_fork(int phnum){
    sem_wait(&mutex);

    state[phnum]=EATING;
    printf("\nPhilosopher %d is hungry",phnum+1);

    test(phnum);

    sem_post(&mutex);

    sem_wait(&S[phnum]);

    sleep(1);
}



void put_fork(int phnum){
    sem_wait(&mutex);
    printf("\nPhilosopher %d puts down fork %d and %d",phnum+1,LEFT+1,phnum+1);
    printf("\nPhilosopher %d is thinking",phnum+1);

    test(LEFT);
    test(RIGHT);

    sem_post(&mutex);
}



void* philosopher(void* num){
    while(1){
        int *i = num;

        sleep(1);

        take_fork(*i);
        
        sleep(0);

        put_fork(*i);
    }
}



void main(){
    int i;
    pthread_t thread_id[N];

    // initialize semaphores
    sem_init(&mutex,0,1);
    for(i=0;i<N;i++){
        sem_init(&S[i],0,0);
    }

    // create thread process
    for(i=0;i<N;i++){
        pthread_create(&thread_id[i],NULL,philosopher,&phil[i]);
        printf("\nPhilosopher %d is thinking",i+1);
    }

    // join thread
    for(i=0;i<N;i++)
        pthread_join(thread_id[i],NULL);


}