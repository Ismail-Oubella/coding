#include<stdio.h>
#include<math.h>
typedef struct  {
    float x;
    float y;
}coords;

void main(){

    coords A,B;
    float dis(coords, coords);

    printf("\nDistance entre 2 points A(x,y) et B(x,y) : ");
    printf("\n-----------------------------------------------\n");

    printf("Remplissage de A : \n");

    printf("x : ");scanf("%f",&A.x);
    printf("y : ");scanf("%f",&A.y);

    printf("\n\n");

    printf("Remplissage de B : \n");

    printf("x : ");scanf("%f",&B.x);
    printf("y : ");scanf("%f",&B.y);

    printf("\nLa distance entre A(%f,%f) et B(%f,%f) est : %f ",A.x,A.y,B.x,B.y,dis(A,B));

}

float dis(coords a, coords b){
    float dis;
    dis=sqrt((pow(b.x-a.x,2))+pow(b.y-a.y,2));

    return dis;
}