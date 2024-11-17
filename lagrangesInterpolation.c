#include<stdio.h>
#include<math.h>

float langranges(float X[], float Y[], float x, int n){
    float ans=0;
    for(int i=0; i<n ;i++){
        float num=1,deno=1;
        float a=X[i];
        for(int j=0;j<n;j++){
            if(j!=i){
                num*=(x-X[j]);
                deno*=(a-X[j]);
            }
        }
        ans+=(num*Y[i])/deno;
    }
    return ans;
}

int main(){
    int n;
    printf("Enter the no. of points : ");
    scanf("%d",&n);
    float X[n],Y[n];
    printf("Enter the x and corresponding y for each point : \n");
    for(int i=0; i<n; i++){
        scanf("%f %f",&X[i],&Y[i]);
    }
    float x;
    printf("enter the value of x : ");
    scanf("%f",&x);
    printf("The value of  Y(%f) = %f",x,langranges(X,Y,x,n));
}
