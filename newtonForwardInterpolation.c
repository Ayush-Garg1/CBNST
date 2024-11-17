#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter n :");
    scanf("%d", &n);
    float x[n], y[n][n];
    printf("Enter the values of x :");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("Enter the values of y :");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &y[i][0]);
    }

    //  FORWARD............
    printf("Forward Differnece table\n");
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%f\t", y[i][j]);
        }
        printf("\n");
    }

    printf("Enter the point of interpolation :");
    float a;
    scanf("%f", &a);
    float h = x[1] - x[0];
    float u = (a - x[0]) / h;
    float sum = y[0][0];
    float p = 1.0;
    for (int j = 1; j < n; j++)
    {
        p = p * (u - j + 1) / j;
        sum = sum + p * y[0][j];
    }
    printf("-> %f\n", sum);
}