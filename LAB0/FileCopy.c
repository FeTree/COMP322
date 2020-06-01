#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("Program name: %s", argv[0]);
    if(argc == 1) {
        printf("\n argcis1, %d", argc);
    }
    if(argc >= 2){
        printf("\nNumber of CLI arguments: %d", argc);

        for(int i = 0; i < argc; i++) {
            printf("\nargv[%d]: %s", i, argv[i]);
        }
    }
    return 0;
}