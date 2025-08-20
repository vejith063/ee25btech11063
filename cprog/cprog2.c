#include <stdio.h>
int  gper(int total,int girls){
    int result=(girls*100)/(total);
    return result;
}
int main()
{
   printf("%d",gper(25,15));

    return 0;
}