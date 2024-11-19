#include <stdio.h>

int arr[50][50] = {0, }, m, n;

int finder(int x, int y);
int main() {
    int count, k, x, y;
    scanf("%d", &count);
    int output[count];
    for (int i = 0; i < count; i++) {
        int result = 0;
        scanf("%d %d %d", &m, &n, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d %d", &x, &y);
            arr[x][y] = 1;
        }
        for (int q = 0; q < m; q++) {
            for (int w = 0; w < n; w++) {
                if(arr[q][w] == 1) {
                    finder(q, w);
                    result++;
                }
            }
        }
        output[i] = result;
    }
    for(int i = 0; i < count; i++) {
        printf("%d\n", output[i]);
    }

}

int finder(int x, int y) {
    arr[x][y] = 0;
    if (x + 1 < m && arr[x + 1][y] == 1) finder(x + 1, y);
    if (x - 1 >= 0 && arr[x - 1][y] == 1) finder(x - 1, y);
    if (y + 1 < n && arr[x][y + 1] == 1) finder(x, y + 1);
    if (y - 1 >= 0 && arr[x][y - 1] == 1) finder(x, y - 1);
    return 0;
}   