#include <stdio.h>

struct xy {
    int x;
    int y;
};
struct xy q[10000000];

int head = 0, rear = 0, a, b;

int enqueue(int n, int m);
int dequeue();

int main() {
    int n, k, cnt = 0, tmp;
    scanf("%d %d", &n, &k);
    enqueue(n, 0);
    while(1) {
        dequeue();
        if(a == k) {
            printf("%d\n", b);
            return 0;
        }
        cnt = b + 1;
        if(a > 0) enqueue(a - 1, cnt);
        if(a <= 100000) enqueue(a + 1, cnt);
        if(a <= 50000) enqueue(a * 2, cnt);
    }
}

int enqueue(int n, int m) {
    //printf("en q[%d] %d %d\n", rear, n, m);
    q[rear].x = n;
    q[rear].y = m;
    rear++;
    return 0;
}

int dequeue() {
    a = q[head].x, b = q[head].y;
    //printf("de q[%d] %d %d\n", head, a, b);
    head++;
    return 0;
}