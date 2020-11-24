#include <stdio.h>
#include <stdlib.h>

int *Data;

void merge(int *seq, int left, int right, int middle) {
    // Initial the temp array
    int size_left = middle - left + 1;
    int size_right = right - middle;
    int Left[size_left], Right[size_right];

    // Put the element into array
    for (int i = 0; i < size_left; i++) {
        Left[i] = seq[left+i];
    }
    for (int i = 0; i < size_right; i++) {
        Right[i] = seq[middle+i+1];
    }

    // Initial the array index
    int i_l = 0, i_r = 0, i_f = 0;

    // Merge two array
    while (i_l < size_left && i_r < size_right) {
        if (Left[i_l] <= Right[i_r]) {
            seq[i_f] = Left[i_l];
            i_l++;
        }
        else {
            seq[i_f] = Right[i_r];
            i_r++;
        }
        i_f++;
    }

    // Put the rest of the Left out 
    while (i_l < size_left) {
        seq[i_f] = Left[i_l];
        i_l++;
        i_f++;
    }

    // Put the rest of the Right out
    while (i_r < size_right) {
        seq[i_f] = Right[i_r];
        i_r++;
        i_f++;
    }
}

void mergeSort(int *seq, int left, int right) {
    // Do the merge sort from the left
    if (left < right) {
        int middle = (left+right) / 2;

        // Recursive
        mergeSort(seq, left, middle);
        mergeSort(seq, middle+1, right);

        // Merge
        merge(seq, left, right, middle);
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

    // Do merge sort
    mergeSort(Data, 0, size-1);

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