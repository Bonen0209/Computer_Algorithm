#include <stdio.h>
#include <stdlib.h>

int *Data, size;

void readData() {
    // Input file names
    char *filename;
    
    // Input a file name
    printf("Please text a input file name: ");
    scanf("%ms", &filename);
    
    // Open the file
    FILE *file;
    file = fopen(filename, "r");

    // Input size
    fscanf(file, "%d", &size);

    // Initialize the array
    Data = (int*) malloc(size*sizeof(int));

    // Put element into array
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &Data[i]);
    }
    fclose(file);
    free(filename);
}

void writeData(int answer) {
    // Output file names
    char *filename;

    // Input a file name
    printf("Please text a output file name: ");
    scanf("%ms", &filename);
    
    // Open the file
    FILE *file;
    file = fopen(filename, "w");

    // Output the answer
    fprintf(file, "%d\n", answer);
    fclose(file);
    free(filename);
}

void insertionsort(int *seq, int left, int right) {
    for (int j = left + 1; j <= right; j++) {
        int key, i;
        key = seq[j];
        i = j - 1;

        while (i > left - 1 && seq[i] > key) {
            seq[i+1] = seq[i];
            i--;
        }

        seq[i+1] = key;
    }
}

int partition(int *seq, int left, int right, int key) {
    int pivot, i, temp;
    pivot = key;
    i = left - 1;
    
    for (int j = left; j <= right; j++) {
        if (seq[j] <= pivot) {
            i++;
            temp = seq[i];
            seq[i] = seq[j];
            seq[j] = temp;
        }
    }

    return i + 1;
}

int findMedians(int *seq, int left, int right) {
    insertionsort(seq, left, right);
    return seq[(left+right)/2];
}

int selection(int *seq, int left, int right, int k) {
    // Return if right - left = 0
    if (right - left == 0) {
        return 0;
    }

    // Divide into groups
    int quotient = (right - left + 1) / 5, remainder = (right - left + 1) % 5;

    // Medians
    int *Median, median_size, median_of_medians;

    if (remainder != 0) {
        median_size = quotient + 1;
    }
    else {
        median_size = quotient;
    }
    Median = (int*) malloc(median_size*sizeof(int));

    // Find the medians
    for (int i = 0; i < quotient; i++) {
        Median[i] = findMedians(Data, left+5*i, left+5*i+4);
    }
    if (remainder != 0) {
        Median[median_size-1] = findMedians(Data, left+5*quotient, left+5*quotient+remainder-1);
    }

    // Find the median of medians
    median_of_medians = findMedians(Median, 0, median_size-1);

    // Partition
    int p = partition(seq, left, right, median_of_medians);

    if (p == k) {
        free(Median);
        return Data[p-1];
    }
    else if (p > k) {
        selection(Data, left, p-1, k);
    }
    else if (p < k) {
        selection(Data, p, right, k);
    }
}

int main() {
    // Read the data
    readData();

    // Input the k
    int k;
    printf("Please input the kth minimum: ");
    scanf("%d", &k);

    // Write the data
    writeData(selection(Data, 0, size-1, k));
    free(Data);

    return 0;
}