#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    double count = 0, sum = 0; 
    double avg;
    scanf("%d", &a);
    double* prt = malloc(sizeof(int) * a);
    for(int i = 0; i < a; i++) {
        scanf("%d", &b);
        count = 0;
        sum = 0;
        double* arr = malloc(sizeof(int) * b);
        for(int j = 0; j < b; j++) {
            scanf("%d", &arr[j]);
            printf("%d\n", arr[j]);
            sum += arr[j];
            printf("sum = %d\n", sum);
        }
        avg = sum / b;
        printf("avg = %lf\n", avg);
        for (int j = 0; j < b; j++) {
            printf("%lf ", arr[j]);
            if (arr[j] > avg) {
                count++;
            }
        }
        printf("count = %d\n", count);
        prt[i] = count / b * 100;
        free(arr);
    }
    for (int i = 0; i < a; i++) {
        printf("%lf%%", prt[i]);
    }

    return 0;
}