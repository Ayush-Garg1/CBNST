#include <stdio.h>
#include <math.h>
#include<string.h>

int main(){
    int n;
    printf("Enter n :");
    scanf("%d", &n);
    float x[n], y[n][n];
    memset(y, 0.0, sizeof(y));
    printf("Enter the values of x :");
    for (int i = 0; i < n; i++){
        scanf("%f", &x[i]);
    }
    printf("Enter the values of y :");
    for (int i = 0; i < n; i++){
        scanf("%f", &y[i][0]);
    }

    //  FORWARD............
    printf("Forward Differnece table\n");
    for (int j = 1; j < n; j++){
        for (int i = 0; i < n - j; i++){
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i; j++){
            printf("%f\t", y[i][j]);
        }
        printf("\n");
    }

    printf("Enter the point of interpolation :");
    float a;
    scanf("%f", &a);
    float h = x[1] - x[0];
    float u = (a - x[n/2]) / h;
    float sum = y[n/2][0];
    float p = 1.0;
    int i = 0;
    float data_mul[n];
    for(int k = 0; k < n; k++){
        data_mul[k] = y[(n/2)-i][k];
        if(k%2) i++;
    }
    float u_mul[n];
    u_mul[0] = p;
    i = 0;
    for (int j = 1; j < n; j++){
        if(j%2 == 1){
            p = p * (u + i) / j;
            i++;
        }
        else{
            p = p*(u-i)/j;
        }
        u_mul[j] = p;
    }
    float ans = 0;
    for(int i = 0; i < n; i++){
        ans += u_mul[i]*data_mul[i];
    }
    printf("\n->%f\n\n", ans);
    return 0;
}
// test case 1
// 1.00 1.05 1.10 1.15 1.20 1.25 1.30
// 2.7183 2.8577 3.0042 3.1582 3.3201 3.4903 3.6693

// test case 2
// 25 30 35 40
// 0.2707 0.3027 0.3386 0.3794