#include <stdio.h>

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    while(1) {
        if(n % 5 == 0) {
            cnt += n / 5;
            break;
        }
        n -= 3;
        cnt++;
        if(n < 0) {
            printf("-1");
            return 0;
        }
    }
    printf("%d", cnt);
}

/*int main() {
    int n, x, a;
    scanf("%d", &n);
    a = -1;
    if ((n % 5) == 0) {
        a = n / 5;
    }
    if ((n - 3) % 5 == 0) {
        if ((n - 3) >= 0)
        a = n / 5 + 1;
    }
    if ((n - 6) % 5 == 0) {
        if ((n - 6) >= 0)
        a = n / 5 + 1;
    }
    if ((n - 9) % 5 == 0) {
        if ((n - 9) >= 0)
        a = n / 5 + 2;
    }
    if ((n - 12) % 5 == 0) {
        if ((n - 12) >= 0)
        a = n / 5 + 2;
    }

    printf("%d", a);
    return 0;
}
*/


