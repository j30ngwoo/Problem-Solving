#include <stdio.h>
#include <stdlib.h> 
int result, m, trees[1000000], count = 0;

int compare(const void *a, const void *b);
int finder(int x, int y);

int main() {
    int n;
    int min = 0, max = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &trees[i]);
        if (trees[i] > max) max = trees[i];
        count++;
    }

    //qsort(trees, n, sizeof(int), compare);
    /*for (int i = 0; i < n; i++) {
        printf("%d ", trees[i]);
    }
    printf("\n");*/
    
    finder(min, max);

    printf("%d", result);
    return 0;
}

int finder(int min, int max) {
    int mid, biggerone = 0;
    long long sum = 0;
    mid = (min + max) / 2;
    for (int i = 0; i < count; i++) {
        if(trees[i] > mid) {
            sum += trees[i] - mid;
            biggerone++;
        }
    }
    //printf("\nmin=%d max=%d m=%d mid=%d sum=%d", min, max, m, mid, sum);
    //printf(" biggerone=%d", biggerone);
    if((sum > m && (sum - biggerone) < m) || sum == m) result = mid;
    else if(sum < m && (sum + biggerone) > m) result = mid - 1;
    else if(sum > m) {
        if(mid == min || mid == max) return -1;
        finder(mid, max);
    }
    else {
        if(mid == min || mid == max) return -1;
        finder(min, mid);
    }
    return 0;
}
