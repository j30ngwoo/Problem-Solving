#include <stdio.h>

int move(int n, int x, int y);
int bigint(int n);

int main() {
    int n, out = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        out *= 2;
    }
    printf("%d\n", out - 1);
    if(n <= 20) move(n, 1, 3);
    return 0;
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