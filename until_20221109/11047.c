#include <stdio.h>

int main() {
    int n, k, sum = 0;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(it i = n - 1; i >= 0; i--) {
        sum += k / arr[i];
        k = k % arr[i];
    }
    printf("%d", sum);
    return 0;
}