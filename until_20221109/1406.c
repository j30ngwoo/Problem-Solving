#include <stdio.h>
#include <string.h>
char str[600001] = "";


int main() {
    int n, length, cursor, x;
    scanf("%s %d", &str, &n);
    length = strlen(str);
    cursor = strlen(str);
    for(int i = 0; i < n; i++) {
        scanf("%c", &x);
        switch(x) {
            case 'L' : if(cursor != 0) cursor--;
            case 'D' : if(cursor != length) cursor++;
            case 'B' : if(cursor != 0) {
                
            }

        }
    }
}