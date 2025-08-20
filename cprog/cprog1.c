#include <stdio.h>
float result(float x,float y){
    float res=x/y;
    return res;
}
int main()
{
   printf("%f",result(3.0,7.0/3.0));

    return 0;
}