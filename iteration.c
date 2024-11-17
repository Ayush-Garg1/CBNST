#include<stdio.h>
#include<math.h>
#include<stdbool.h>

float f(float x){
    // return cos(x)-3*x+1;
    // return 2*x-log10(x)-7;
    // return x-exp(-x);
    return cos(x)-x*exp(x);
}

float g(float x){
    // return (cos(x)+1)/3.0;
    // return (log10(x)+7)/2.0;
    // return exp(-x);
    return cos(x)/exp(x);
}

float d(float x){
    // return (-sin(x))/3.0;
    // return 1/(2.0*x*log(10));
    // return -exp(-x);
    return (-sin(x)*exp(-x) - cos(x)*exp(-x));
}

void evalute(float a, float error){
    int i = 1;
    printf("Iteration\tx\t\tf(x)\n");
    while(true){
        float gx = g(a);
        printf("%d\t\t%f\t%f\n", i++, a, gx);
        if(fabs(f(gx)) <= error){
            printf("Root is %f after %d iterations\n", a, i-1);
            break;
        }
        a = gx;
    }
}

int main(){
    float a, error;
    while(true){
        printf("Enter the intial guess : ");
        scanf("%f", &a);
        if(fabs(d(a)) < 1){
            printf("Enter the tolerable error : ");
            scanf("%f", &error);
            evalute(a, error);
            break;
        }else{
            printf("Try again...\n");
        }
    }
}