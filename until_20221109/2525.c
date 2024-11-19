#include <stdio.h>

int main() {
    int h, m, c;
    scanf("%d %d %d", &h, &m, &c);
    m += c;
    while (m >= 60) {
        m -= 60;
        h++;
    }
    h %= 24;
    printf("%d %d", h, m);
    
    return 0;
}