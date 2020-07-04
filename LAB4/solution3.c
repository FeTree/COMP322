/*
David Eisenbaum
COMP322 
LAB4
Due: 7/3/2020
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5 //the number of philosophers
sem_t S[N]; //semaphores for chopsticks

// Functions
void *philospher(void *num);
void take_chopsticks(int);
void put_chopsticks(int);

int phil_num[N] = {0, 1, 2, 3, 4}; //philosopher ID

int main()
{
    int i;
    pthread_t thread_id[N];
    for (i = 0; i < N; i++)
        sem_init(&S[i], 0, 1);
    for (i = 0; i < N; i++)
        pthread_create(&thread_id[i], NULL, philospher, &phil_num[i]);
    for (i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);
}

void *philospher(void *num)
{
    while (1)
    {
        int *i = num;
        take_chopsticks(*i);
        put_chopsticks(*i);
    }
}
void take_chopsticks(int ph_num)
{
    //check if oddd
    if (ph_num  % 2 == 1)
    {
        sem_wait(&S[ph_num % N]); // take left chopstick
        printf("Philosopher %d takes chopstick %d \n", ph_num, ph_num);
        sleep(1);
    }
    //even
    else {
        sem_wait(&S[(ph_num + 1) % N]); //take the right chopstick
        printf("Philosopher %d takes chopstick %d \n", ph_num, (ph_num + 1) % N);
        sleep(1);
    }
}
void put_chopsticks(int ph_num)
{
    //odd pick up right
    if (ph_num % 2 == 1)
    {
        sem_post(&S[(ph_num + 1) % N]); //put the right chopstick
        printf("Philosopher %d putting chopstick %d \n", ph_num, (ph_num + 1) % N);

        sleep(1);
    }
    else {
        sem_wait(&S[ph_num % N]); // take left chopstick
        printf("Philosopher %d takes chopstick %d \n", ph_num, ph_num);
        sleep(1);
    }
}