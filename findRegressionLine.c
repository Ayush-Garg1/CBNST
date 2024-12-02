#include<stdio.h>
#define S 50
int main()
{
    int n, i;
    float x[S], y[S], sumX=0, sumY=0, sumX2=0, sumY2=0, sumXY=0;
    float b1, a1, b2, a2;
    printf("How many data points?\n");
    scanf("%d", &n);
    printf("Enter data:\n\tx y\n");
    for(i=1; i<=n; i++) {
        printf("[%d]:\t", i);
        scanf("%f %f", &x[i], &y[i]);
    }
    for(i=1; i<=n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
        sumXY += x[i] * y[i];
    }
    b1 = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a1 = (sumY - b1 * sumX) / n;
    b2 = (n * sumXY - sumX * sumY) / (n * sumY2 - sumY * sumY);
    a2 = (sumX - b2 * sumY) / n;
    printf("\nRegression Line y on x: y = %.2f + %.2fx\n", a1, b1);
    printf("Regression Line x on y: x = %.2f + %.2fy\n", a2, b2);
    return 0;
}
