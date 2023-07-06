#include<stdio.h>
int main(){

    int somme=0;

    printf("the sum of first 10 natural numbers is:");

    for (int i=1 ; i<=10 ; i++)
        somme=somme+i;

    printf(" %d",somme);


    return 0;
}