#include <stdio.h>

int main() {
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        count += checker();
    }
    printf("%d\n", count);
}

int checker() {
    int n;
    char array[100];
    scanf("%s", &array);
    for (int i = 0; i < sizeof(array); i++) {
        
    }
    return ;
}