#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *Data;
double START, END;
const int k = 5;

void insertionsort(int *seq, int left, int right) {
    for (int j = left+1; j < right+1; j++) {
        int key, i;
        key = seq[j];
        i = j - 1;

        while (i > left-1 && seq[i] > key) {
            seq[i + 1] = seq[i];
            i--;
        }

        seq[i + 1] = key;
    }
}

int partition(int *seq, int left, int right) {
    int pivot, i, temp;
    pivot = seq[right];
    i = left - 1;
    
    for (int j = left; j < right; j++) {
        if (seq[j] <= pivot) {
            i++;
            temp = seq[i];
            seq[i] = seq[j];
            seq[j] = temp;
        }
    }

    temp = seq[i+1];
    seq[i+1] = seq[right];
    seq[right] = temp;
    return i + 1;
}

void combine(int *seq, int left, int right) {
    if (left < right) {
        int middle;
        middle = partition(seq, left, right);
        
        if (middle - left > k) {
            combine(seq, left, middle-1);
        }
        else {
            insertionsort(seq, left, middle-1);
        }
        
        if (right - middle > k) {
            combine(seq, middle+1, right);
        }
        else {
            insertionsort(seq, middle+1, right);
        }
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
    combine(Data, 0, size-1);

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