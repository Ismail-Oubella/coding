#include<stdio.h>
#include"mybibc.h"
int main(){

    int a,b;
    void signe(int , int);
    int max(int ,int);
    int min(int , int );

    printf("a=");scanf("%d",&a);
    printf("b=");scanf("%d",&b);

    signe(a,b);

    printf("\n");

    printf("Max(%d,%d)=%d || Min(%d,%d)=%d",a,b,max(a,b),a,b,min(a,b));

    return 0;
}   

