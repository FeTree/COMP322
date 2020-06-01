#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("Program name: %s", argv[0]);
    if(argc == 2) {
        printf("\n Invalid input");
    }
    if(argc >= 3){
        printf("\nNumber of CLI arguments: %d", argc);

        for(int i = 0; i < argc; i++) {
            printf("\nargv[%d]: %s", i, argv[i]);
        }
    }
    return 0;
}