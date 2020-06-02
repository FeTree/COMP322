#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    //Check command line arguments
    if(argc == 2) {
        printf("\n Invalid input, not enough arguments\n");
    }
    else if(argc == 3){
        // printf("\nNumber of CLI arguments: %d\n", argc);
    }
    else {
        printf("\nExceeded limit of arguments\n");
    }

    // Our files
    FILE *inputFile;
    FILE *outputFile;
    char inputFileName[100];
    char outputFileName[100];
    char c; // used to parse through input 

    //Assign filenames from command line
    strcpy(inputFileName, argv[1]);
    strcpy(outputFileName, argv[2]);
    

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