#include <stdio.h>

int arr[300][300];
int tmp[300][300];
int n, m;

int turn(int cnt);
int turn2(int cnt);

int main() {
    int r, min, cnt = 0;
    scanf("%d %d %d", &n, &m, &r);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    if(n <= m) min = n;
    else min = m;

    for(int i = 0; i < r / 2; i++) {
        for(int j = 0; j < min / 2; j++) {
            turn(cnt);
            cnt++;
        }
        cnt = 0;
        for(int j = 0; j < min / 2; j++) {
            turn2(cnt);
            cnt++;
        }
        cnt = 0;
    }
    if(r % 2 == 1) {
        for(int j = 0; j < min / 2; j++) {
            turn(cnt);
            cnt++;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                printf("%d ", tmp[i][j]);
            }
            printf("\n");
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

int turn(int cnt) {
    for(int i = cnt; i < n - cnt - 1; i++) {
        tmp[i + 1][cnt] = arr[i][cnt];
    }
    for(int i = cnt; i < m - cnt - 1; i++) {
        int a = n - cnt - 1;
        tmp[a][i + 1] = arr[a][i];
    }
    for(int i = n - cnt - 1; i > cnt; i--) {
        int a = m - cnt - 1;
        tmp[i - 1][a] = arr[i][a];
    }
    for(int i = m - cnt - 1; i > cnt; i--) {
        tmp[cnt][i - 1] = arr[cnt][i];
    }
    return 0;
}

int turn2(int cnt) {
    for(int i = cnt; i < n - cnt - 1; i++) {
        arr[i + 1][cnt] = tmp[i][cnt];
    }
    for(int i = cnt; i < m - cnt - 1; i++) {
        int a = n - cnt - 1;
        arr[a][i + 1] = tmp[a][i];
    }
    for(int i = n - cnt - 1; i > cnt; i--) {
        int a = m - cnt - 1;
        arr[i - 1][a] = tmp[i][a];
    }
    for(int i = m - cnt - 1; i > cnt; i--) {
        arr[cnt][i - 1] = tmp[cnt][i];
    }
    return 0;
}