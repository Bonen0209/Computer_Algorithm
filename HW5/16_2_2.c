#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int N, C;
int *Value, *Weight, *Backpack;

int main() {

    printf("Please input the number of items: ");
    scanf("%d", &N);

    Value = (int*) malloc(N*sizeof(int));
    Weight = (int*) malloc(N*sizeof(int));

    for (int i = 0; i < N; i++) {
        printf("Please input each item value: ");
        scanf("%d", &Value[i]);
    }

    for (int i = 0; i < N; i++) {
        printf("Please input each item weight: ");
        scanf("%d", &Weight[i]);
    }

    printf("Please input the backpack's capacity: ");
    scanf("%d", &C);

    Backpack = (int*) malloc((C+1)*sizeof(int));
    memset(Backpack, 0, sizeof(Backpack));

    for (int i = 0; i < N; i++) {
        for (int j = C; j >= Weight[i]; j--) {
            Backpack[j] = fmax(Backpack[j], Backpack[j-Weight[i]] + Value[i]);
        }
    }

    printf("Maximum value is %d\n", Backpack[C]);

    free(Value);
    free(Weight);
    free(Backpack);
    return 0;
}