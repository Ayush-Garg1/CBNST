#include<stdio.h>
#include<math.h>
#include<stdbool.h>

float f(float x){
    return 3*x-cos(x)-1;
}

float d(float x){
    return 3 + sin(x);
}

int main(){
    float a, error, x, fx, f1;
    int i = 1;
    printf("Enter the intial guess : ");
    scanf("%f", &a);
    printf("Enter the tolerable error : ");
    scanf("%f", &error);
    do{
        x = a - f(x)/d(x);
        printf("%d\t\t%f\t%f\t%f\t%f\n", i++, a, f(x), d(x), x);
        a = x;
        f1 = f(a);
    }while(fabs(f1) > error);
    printf("Root is %f after %d iterations\n", a, i-1);
}