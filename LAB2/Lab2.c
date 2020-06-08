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

    //Print out parent pid
    printf("The parent pid is %d\n", getpid());

    // Loop to create child processes and output helloworld
    for(int i = 0; i < processes; i++) {

        // Fork the process
        int j = fork();

        // if fork equals 0 successful child process created
        if(j == 0) {
            printf("Hello world from child %d\n", i);
            exit(0);
        }
        else {
            //wait for child to terminate
            wait(&j);
        }
    }
    


    return 0;
}