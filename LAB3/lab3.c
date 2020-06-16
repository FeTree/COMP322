/*
David Eisenbaum
COMP322
LAB 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Globals
int average;
int maximum;
int minimum;
int numbers[100];
int lengthOfNumberList;

void *findAverage() {
    int sum = 0;
    for(int i = 0; i < lengthOfNumberList ; i++){
        printf("%d\n", numbers[i]);
        sum += numbers[i];
    }

    average = sum / lengthOfNumberList;
    return NULL;
}

int main() {
    // Generate random numbers 
    lengthOfNumberList = 0;
    printf("Enter how many numbers to be generated (between 0-100)\n");
    scanf("%d", &lengthOfNumberList);

    //Store random numbers in array
    for(int i = 0; i < lengthOfNumberList; i++){
        numbers[i] = rand() % 101;
    }

    // Thread 1
    pthread_t t_id_1;
    printf("Before using threading\n");
    pthread_create(&t_id_1, NULL, findAverage, NULL);
    pthread_join(t_id_1, NULL);

    printf("Average: %d\n", average);


    exit(0);
}