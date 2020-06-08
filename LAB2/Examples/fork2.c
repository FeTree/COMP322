    #include <stdio.h>

     int main()

     {

            int pid;

            /* fork another process */

            pid = fork();

            if (pid < 0)

            {

                    /* error occurred */

                    printf("Fork Failed\n");

                    exit(-1);

            }

            else if (pid == 0)

            {

                    /* child process */

                    execlp("/bin/ls","ls",NULL);

            }

            else

            {

                    /* parent process */

                    /* parent will wait for the child to complete */

                    wait();

                   

                    printf("Child Complete\n");

                    exit(0);

            }

            return 0;

     }