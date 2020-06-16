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
        sum += numbers[i];
    }

    average = sum / lengthOfNumberList;
    return NULL;
}

void *findMax() {
    int first = numbers[0];
    for(int i = 0; i < lengthOfNumberList; i++){
        if(numbers[i] > first) {
            first = numbers[i];
        }
    }

    maximum = first;
}

void *findMin() {
    int first = numbers[0];
    for(int i = 0; i < lengthOfNumberList; i++){
        if(numbers[i] < first) {
            first = numbers[i];
        }
    }

    minimum = first;
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

    //Print array for users
    printf("Generated numbers: ");
    for(int i = 0; i < lengthOfNumberList; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Thread 1
    pthread_t t_id_1;
    pthread_create(&t_id_1, NULL, findAverage, NULL);
    pthread_join(t_id_1, NULL);


    // Thread 2
    pthread_t t_id_2;
    pthread_create(&t_id_2, NULL, findMax, NULL);
    pthread_join(t_id_2, NULL);

    // Thread 3
    pthread_t t_id_3;
    pthread_create(&t_id_3, NULL, findMin, NULL);
    pthread_join(t_id_3, NULL);


    // Print Results
    printf("Average: %d\n", average);
    printf("Maximum: %d\n", maximum);
    printf("Minimum: %d\n", minimum);


    exit(0);
}