#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    printf("This program creates multi processes of hello world\n");

    //Get user input for how many processes to create
    int processes = 0;
    printf("How many processes do you want to create?\n");
    scanf("%d", &processes);
    


    return 0;
}