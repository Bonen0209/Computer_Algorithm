#include <stdio.h>
#include <stdlib.h>

const int size = 10000;

int main() {
    // Output file names
    char *filename;

    // Input a file name
    printf("Please text a output file name: ");
    scanf("%ms", &filename);
    
    // Open the file
    FILE *file;
    file = fopen("input.txt", "w");

    // Output the size
    fprintf(file, "%d\n", size);

    // Output the array
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", i);
    }
    fclose(file);
    free(filename);

    return 0;
}