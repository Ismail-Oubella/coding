#include<stdio.h>
#define N 200
void main(){

    int tab[N],copy[N],n,k;

    printf("sort elements of array in ascending order.");
    printf("\n---------------------------------------------------------------------------\n");


    do
    {

        printf("input the number of elements to be sorted in the array : ");
        scanf("%d",&n);

    }while(n>N || n<=0);

    printf("input %d elemnets in the array :\n",n);

    for(int i=0; i<n; i++)
    {
        printf("elemente - %d : ",i);
        scanf("%d",&tab[i]);
        copy[i]=tab[i];
    }

    printf("elements of array in sorted ascending order : \n");

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(copy[j+1]<=copy[j])
            {
                k=copy[j];
                copy[j]=copy[j+1];
                copy[j+1]=k;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("%d ", copy[i]);
    }


}