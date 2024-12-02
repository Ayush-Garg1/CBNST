#include <stdio.h>
int main() {
    int n, i;
    double x[100], y[100], sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0, a, b;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the values\n  \tx y\n");
    for (i = 0; i < n; i++) {
        printf("[%d]: \t", i + 1);
        scanf("%lf %lf", &x[i], &y[i]);
    }
    for (i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }
    b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    a = (sum_y - b * sum_x) / n;
    printf("\nThe linear equation is: y = %.2lf + %.2lfx\n", a, b);
    return 0;
}
