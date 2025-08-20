#include <stdio.h>
void series(int n){
    int k;
    for(k=5;k<9;k=k+1){
        if(k==5){
            printf("%d/%d\n",-k,n*k);
        }else{
            printf("%d/%d\n",k,-n*k);
        }
    }
}
int main()
{
    series(6);

    return 0;
}
