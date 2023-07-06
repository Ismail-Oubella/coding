#include<stdio.h>
int main(){

    int A[100][100],max[100][100],min[100][100],Max[100],Min[100];
    int La,Ca;

    do
    {

        printf("Input the number of elements to store in the line of A:");
        scanf("%d",&La);

    } while (La<=0 || La>100);

    do
    {

        printf("Input the number of elements to store in the column A:");
        scanf("%d",&Ca);

    } while (Ca<=0 || Ca>100);

    printf("Input(%d*%d) elements in the array C:\n",La,Ca);

    for (int i=0 ; i<La ; i++){
        
        for (int j=0 ; j<Ca ; j++){

            printf("A[%d][%d]=",i,j);
            scanf("%d",&A[i][j]);

        } 

    }

    printf("\nLa matrice A est:\n");

    for (int i=0 ; i<La ; i++){
        
        for (int j=0 ; j<Ca ; j++){

            printf("%d ", A[i][j]);

        } 

        printf("\n");

    }

    //MAX
    for (int i=0 ; i<La ; i++){

        Max[i]=A[i][0];
        
        for (int j=0 ; j<Ca ; j++){

            if(A[i][j] >= Max[i]){

                Max[i]=A[i][j];

            }

        } 

    }

    for (int i=0 ; i<La ; i++){
        
        for (int j=0 ; j<Ca ; j++){

            if(A[i][j] == Max[i]){

                max[i][j]=1;

            }

            else{

                max[i][j]=0;

            }

        } 

    }

    printf("Matrice de Max:\n");


    for (int i=0 ; i<La ; i++){
        
        for (int j=0 ; j<Ca ; j++){

            printf("%d ", max[i][j]);

        } 

        printf("\n");

    }

    //MIN

    for (int j=0 ; j<Ca ; j++){

        Min[j]=A[0][j];
        
        for (int i=0 ; i<La ; i++){

            if(A[i][j] <=  Min[j]){

                Min[j]=A[i][j];

            }

        } 

    }

    for (int j=0 ; j<Ca ; j++){
        
        for (int i=0 ; i<La ; i++){

            if(A[i][j] == Min[j]){

                min[i][j]=1;

            }

            else{

                min[i][j]=0;

            }

        } 

    }

    //piot de 

    for(int i=0 ; i<La ; i++){

        for(int j=0 ; j<Ca ; j++){

            if(max[i][j]==1 && min[i][j]==1){

                printf("La position (%d,%d)  est un point-col",i,j);

            }


        }

    }

    return 0;
}