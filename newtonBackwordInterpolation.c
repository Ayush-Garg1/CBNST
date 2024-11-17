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
    
    printf("Backward Differnece table\n");
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            printf("%f\t",y[i][j]);
        printf("\n");
    }

    printf("Enter the point of interpolation :");
    float a;
    scanf("%f", &a);
    float h = x[1] - x[0];
    float u = (a - x[n-1]) / h;
    float sum = y[n-1][0];
    float p = 1.0;
    for (int j = 1; j < n; j++)
    {
        p = p * (u + j-1) / (j);
        sum = sum + p * y[n-1][j];
    }
    printf("-> %f\n", sum);
}

/*

y(n-1) + u*y(n-1) + u*(u+1)/2*y(n-1) + u*(u+1)/2*(u+2)/3*y(n-1) + u*(u+1)/2*(u+2)/3*(u+3)/4*y(n-1)

*/