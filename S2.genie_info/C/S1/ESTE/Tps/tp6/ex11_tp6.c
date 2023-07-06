#include<stdio.h>
#include <stdbool.h>
void main(){

    int n;
    bool premier(int );

    printf("\npremier ou non ? et le prochain : ");
    printf("\n------------------------------------\n");

    printf("n : ");
    scanf("%d", &n);

    printf("%d est il premier ? ",n);

    /*--------------------------------------------using function premier ou non----------------------------------------------------------*/

    if(premier(n)){printf(" TRUE");}
    else{printf(" FALSE");}

    printf("\n");

    /*--------------------------------------------using function prochain----------------------------------------------------------------*/


    int prochainPremier(int );

    printf("Le prochain premier est : %d",prochainPremier(n));

}

bool premier(int n){
    bool k=true;

    for(int i=2 ; i<n/2 ; i++)
    {
        if(n%i == 0)
        {
            k=false;
            break;
        }
    }
    return k;
}

int prochainPremier(int n ){
    int k,j;

    k=n;
    do
    {
        j=1;
        k++;
        for(int i=2 ; i<k/2 ; i++)
        {
            if(k % i == 0)
            {
                j--;
                break;
            }
        }
    }while(j==0);
    return k;
}