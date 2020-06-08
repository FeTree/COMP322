/*
    David Eisenbaum
    COMP322
    LAB2
    Due: June 11
    This program creates a multi-processed hello world according to user input
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()

{

  const int BASE_PROCESSES = 3;

  int i, j;

  for(i = 0; i < BASE_PROCESSES; i++)

  {

      j = fork();

      if(j == 0)

      {

          printf("%s %d", "My ppid is ", getppid());

          printf("%s %d.\n", " and my pid is ", getpid());

          sleep(2);

      }

      else

        wait(&j);

  }

  return (0);

}