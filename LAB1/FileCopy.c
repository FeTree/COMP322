#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    //Check command line arguments
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

    // Our files
    FILE *inputFile;
    FILE *outputFile;
    char inputFileName[100] = argv[1];
    char outputFileName[100] = argv[2];
    char c; // used to parse through input 

    // Open input file
    inputFile = fopen(inputFileName, "r");
    if(inputFile == NULL) {
        printf("Input file, %s, does not exist\n", inputFileName);
        exit(0);
    }

    // Open output file
    outputFile = fopen(outputFileName, "w");
    if(outputFile == NULL) {
        printf("%s does not exist\n", outputFileName);
        exit(0);
    }

    //Read from input
    c = fgetc(inputFile);
    while (c != EOF) {
        fputc(c, outputFile); // put current char into output
        c = fgetc(inputFile); // advance to the next char
    }

    printf("Successful copy to output from %s to %s\n", inputFileName, outputFileName);

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    
    return 0;
}