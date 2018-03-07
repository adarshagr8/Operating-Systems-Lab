#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>

#define N 5

sem_t forks[N];
 
void initSemaphores() {
    
    int i;
    for (i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);
    } 
} 

void *philosopher(void *arg) {

    int index = (int) arg;
    sleep(2);
    printf("Philosopher %d, is hungry\n", index);
  
    if (index == N - 1){
        sem_wait(&forks[(index + 1)%N]);
    }
    else {
        sem_wait(&forks[index]);
    } 

    printf("Philosopher %d, picked up 1 fork\n", index);
    sleep(1);
  
    if (index == N - 1){
        sem_wait(&forks[index]);
    }
    else {
        sem_wait(&forks[(index + 1)%N]);
    }
    
  
    printf("Philosopher %d, picked up both forks (right and left) \n", index);
    sleep(1);
  
    printf("Philosopher %d, is eating \n", index);
    sleep(3);
    
   
    if (index == N - 1){
        sem_post(&forks[(index + 1)%N]);
    }
    else {
        sem_post(&forks[index]);
    }
   
    printf("Philosopher %d, dropped up 1 fork\n", index);
    sleep(1);
   
    if (index == N - 1){
        sem_post(&forks[index]);
    }
    else {
        sem_post(&forks[(index + 1)%N]);
    }
    
   
    printf("Philosopher %d, dropped up both fork (dropped both)\n", index);
    sleep(1);
   
    printf("Philosopher %d, is thinking\n", index);

        
}      
      
        
int main() {
            
    initSemaphores();
   
    pthread_t philosophers[N];
    
    int i;
    for (i = 0; i < N; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, (void *)i);
    }
    
    for (i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }
    
    return 0;
}
