#include<stdio.h>
#include<math.h>
#include<stdbool.h>

float f(float x){
    // return pow(x, 3)-x-1;
    return x*log10(x)-1.2;
}

void evaluate(float a, float b, float error){
    int i = 1;
    printf("Iteration\tx\t\tf(x)\n");
    while(true){
        float x = (a+b)/2;
        float fx = f(x);
        printf("%d\t\t%f\t%f\n", i++, x, fx);
        if(fabs(fx) <= error){
            printf("Real root of the equation is : %f after %d iterations", x, i-1);
            break;
        }
        if(fx < 0)  a = x;
        else    b = x;
    }
}

int main(){
    float a, b, error;
    while(true){
        printf("Enter the interval : ");
        scanf("%f %f", &a, &b);
        if(f(a)*f(b) < 0){
            printf("Enter the tolerable error : ");
            scanf("%f", &error);
            evaluate(a, b, error);
            break;
        }else{
            printf("Invalid interval... Try again...\n");
        }
    }
}