#include<stdio.h>
int main(){

    float x,y;

    printf("Ce programme permet de detecter la nature de produit (X*Y) si il est positif ou negatif.\n");

    printf("X=");
    scanf("%f",&x);

    printf("Y=");
    scanf("%f",&y);

    if(x>=0 && y>=0 || x<=0 && y<=0){printf("Postif");}
    else{printf("negatif");}

    return 0;
}