#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double x1, y1, x2, y2, r1, r2, distance;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
        distance = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
        if(x1 == x2 && y1 == y2 && r1 == r2) {
            printf("-1\n");
        }
        else if(distance == r1 + r2 || distance == fabs(r1 - r2)) {
            printf("1\n");
        }
        else if(distance < (r1 + r2) && distance > fabs(r1 - r2)) {
            printf("2\n");
        }
        else {
            printf("0\n");
        }
    }
    return 0;
}