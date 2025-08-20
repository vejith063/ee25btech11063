#include <stdio.h>
#include<math.h>
float len(float d){
    float cf=M_PI*d;
    return cf;
}
float cost(float dia,float cpm){
    float circum;
    circum=M_PI*dia;
    float res=circum*cpm;
    return res;
}
int main(){
   printf("length is %f\n",len(1.5));
   printf("cost is %f",cost(1.5,15.0));

    return 0;
    }