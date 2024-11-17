#include<stdio.h>
#include<math.h>
#include<stdbool.h>

float f(float x){
    return pow(x, 3)-5*x+1;
    // return x*x*exp(-x/2.0)-1;
}

void evaluate(float a, float b, float error){
    int i = 1;
    printf("Iteration\tx\t\tf(x)\n");
    while(true){
        if(f(b) == f(a)){
            printf("METHOD FAILED......\n");
            return;
        }
        float x = b - ((b-a)/(f(b)-f(a)))*f(b);
        float fx = f(x);
        printf("%d\t\t%f\t%f\n", i++, x, fx);
        if(fx <= error){
            printf("Root is %f after %d iterations\n", x, i-1);
            break;
        }
        a = b;
        b = x;
    }
}

int main(){
    float a, b, error;
    while(true){
        printf("Enter the values of x0 and x1 : ");
        scanf("%f %f", &a, &b);
        if((f(a)*f(b)) < 0){
            printf("Enter the tolerable error : ");
            scanf("%f", &error);
            evaluate(a, b, error);
            break;
        }else{
            printf("Try again...\n");
        }
    }
}