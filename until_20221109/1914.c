#include <stdio.h>

int arr[40] = {0, };

int move(int n, int x, int y);
int bigint(int n);

int main() {
    int n;
    scanf("%d", &n);
    bigint(n);
    if(n <= 20) move(n, 1, 3);
    return 0;
}

int bigint(int n) {
    int tmp, end = 0, count = 0;
    arr[0] = 1;
    for(int i = 0; i < n; i++) {
        if(arr[end] * 2 >= 10) end++;
        for(int j = end; j >= 0; j--) {
            tmp = arr[j] * 2;
            arr[j] = tmp % 10;
            if(tmp >= 10) arr[j + 1]++;
        }
    }
    for(int i = end; i > 0; i--) printf("%d", arr[i]);
    printf("%d\n", arr[0] - 1);
}

int move(int n, int x, int y) {
    if(n == 1) {
        printf("%d %d\n", x, y);
    }
    else {
        move(n - 1, x, 6 - x - y);
        printf("%d %d\n", x, y);
        move(n - 1, 6 - x - y, y);
    }
    return 0;
}