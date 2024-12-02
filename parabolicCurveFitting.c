#include <stdio.h>
int main()
{
    int n;
    float sx = 0, sy = 0, sxy = 0, sx2y = 0, sx2 = 0, sx3 = 0, sx4 = 0, a, b, c, ratio;

    printf("Enter no. of points: ");
    scanf("%d", &n);

    float x[n], y[n], table[3][4];

    printf("Enter values of x: ");
    for (int i = 0; i < n; i++) scanf("%f", &x[i]);

    printf("Enter values of y: ");
    for (int i = 0; i < n; i++) scanf("%f", &y[i]);

    for (int i = 0; i < n; i++)
    {
        sx += x[i];
        sy += y[i];
        sxy += x[i] * y[i];
        sx2y += x[i] * x[i] * y[i];
        sx2 += x[i] * x[i];
        sx3 += x[i] * x[i] * x[i];
        sx4 += x[i] * x[i] * x[i] * x[i];
    }
    table[0][0] = n; table[0][1] = sx; table[0][2] = sx2; table[0][3] = sy;
    table[1][0] = sx; table[1][1] = sx2; table[1][2] = sx3; table[1][3] = sxy;
    table[2][0] = sx2; table[2][1] = sx3; table[2][2] = sx4; table[2][3] = sx2y;

    // Applying Gauss Elimination Method to find a, b, c
    ratio = table[2][0] / table[0][0];
    for (int i = 0; i < 4; i++) {
        table[2][i] -= table[0][i] * ratio;
    }

    ratio = table[1][0] / table[0][0];
    for (int i = 0; i < 4; i++) {
        table[1][i] -= table[0][i] * ratio;
    }

    ratio = table[2][1] / table[1][1];
    for (int i = 0; i < 4; i++) {
        table[2][i] -= table[1][i] * ratio;
    }

    c = table[2][3] / table[2][2];
    b = (table[1][3] - table[1][2] * c) / table[1][1];
    a = (table[0][3] - table[0][2] * c - table[0][1] * b) / table[0][0];

    printf("\nValue of a = %.2f \nValue of b = %.2f\nValue of c = %.2f\n", a, b, c);
    printf("The second degree parabolic curve fitting equation is: y = %.2lf + %.2lfx + %.2lfx^2\n", a, b,c);
    return 0;
}
