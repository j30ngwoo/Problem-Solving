#include <stdio.h>
#include <stdlib.h>

int n, m, front = 0, rear = 1, count = 0, maze[100][100], dist[100][100], queue[10001][2], out[2];

int enqueue(int x, int y) {
    queue[rear][0] = x; 
    queue[rear][1] = y;
    rear++;
    return 0;
}

int dequeue() {
    out[0] = queue[front][0];
    out[1] = queue[front][1];
    front++;
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }
    int xp[4] = {1, 0, -1, 0};
    int yp[4] = {0, 1, 0, -1};
    
    queue[0][0] = 0;
    queue[0][1] = 0;
    
    while(1) {
        int newx = queue[front][0];
        int newy = queue[front][1];
        for(int i = 0; i < 4; i++) {
            int nowx = newx + xp[i];
            int nowy = newy + yp[i];
            if(nowx >= 0 && nowx < n && nowy >= 0 && nowy < m) {
                if (maze[nowx][nowy] == 1) {
                    enqueue(nowx, nowy);
                    maze[nowx][nowy] += maze[newx][newy];
                } 
                if(nowx + 1 == n && nowy + 1 == m) {
                    printf("%d", maze[nowx][nowy]);
                    return 0;
                }
            }
        }
        dequeue();
    }
    return 0;
}