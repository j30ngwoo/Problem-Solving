#include <stdio.h>
#include <string.h>

int queue[10001] = {0, };

int main() {
    int n, num = 0, value;
    char fn[6];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", &fn); 
        if(strcmp(fn, "push") == 0) {
            scanf("%d", &value);
            queue[num] = value;
            num++;
        }

        else if(strcmp(fn, "pop") == 0) {
            if (queue[0] == 0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", queue[0]);
                for (int i = 0; i < num; i++) {
                    queue[i] = queue[i + 1];
                }
                num--;
            }
        }

        else if(strcmp(fn, "size") == 0) {
            printf("%d\n", num);
        }

        else if(strcmp(fn, "empty") == 0) {
            if (num == 0) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }

        else if(strcmp(fn, "front") == 0) {
            if (num == 0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", queue[0]);
            }
        }

        else if(strcmp(fn, "back") == 0) {
            if (num == 0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", queue[num - 1]);
            }
        }
    }
    return 0;
}