#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("Program name: %s", argv[0]);
    if(argc == 2) {
        printf("\n Invalid input, not enough arguments\n");
    }
    else if(argc == 3){
        printf("\nNumber of CLI arguments: %d\n", argc);

        for(int i = 0; i < argc; i++) {
            printf("\nargv[%d]: %s", i, argv[i]);
        }
    }
    else {
        printf("\nExceeded limit of arguments\n");
    }
    
    return 0;
}