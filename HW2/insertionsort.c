#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *Data;
double START, END;

void insertionsort(int *seq, int size) {
    for (int j = 1; j < size; j++) {
        int key, i;
        key = seq[j];
        i = j - 1;

        while (i > -1 && seq[i] > key) {
            seq[i + 1] = seq[i];
            i--;
        }

        seq[i + 1] = key;
    }
}

int main() {
    // Input and Output file names
    char *filename;
    
    // Input a filename
    printf("Please text a input file name: ");
    scanf("%ms", &filename);
    
    // Open the file
    FILE *file;
    file = fopen(filename, "r");

    // Input size
    int size;
    fscanf(file, "%d", &size);

    // Initialize the array
    Data = (int*) malloc(size*sizeof(int));

    // Put element into array
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &Data[i]);
    }
    fclose(file);
    free(filename);

    // Start time
    START = clock();

    // Do insertion sort
    insertionsort(Data, size);

    // End time
    END = clock();

    // Print the total time
    printf("The total time is %d\n", (END-START)/CLOCKS_PER_SEC);

    // Input a file name
    printf("Please text a output file name: ");
    scanf("%ms", &filename);
    
    // Open the file
    file = fopen(filename, "w");

    // Output the size
    fprintf(file, "%d\n", size);

    // Output the array
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", Data[i]);
    }
    fclose(file);
    free(filename);
    free(Data);

    return 0;
}