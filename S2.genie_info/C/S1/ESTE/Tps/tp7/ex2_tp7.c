#include <stdlib.h>
#include <stdio.h>
void main(){

    int a = 10;// id : a , adress : 1000 , valeur : 10 ;
    int b = 5;// id : b , adress : 1002 , valeur : 5 ;
    int tab[3] = {1,2,3};// id : tab , adress : 1004 , valeur : tab[0]=1/tab[1]=2/tab[2]=3 ;
    int *p_tab;// id : p_tab , adress : 1010 , valeur : ?? ;


    tab[0] = a;// id : tab[0] , adress : 1004 , valeur : 10 ;
    *(tab + 1) = b;// id : tab[1] , adress : 1006 , valeur : 5 ;
    p_tab = tab + 2;// id : p_tab , adress : 1010 , valeur : &tab[2] ;


    *p_tab = *(p_tab - 1);// id : tab[2] , adress : 1008 , valeur : 5 ;
    --p_tab;// id : p_tab , adress : 1010 , valeur : &tab[1] ;
    *p_tab = *(p_tab- 1);// id : tab[1] , adress : 1006 , valeur : 10 ;
    --p_tab;// id : p_tab , adress : 1010 , valeur : &tab[0] ;
    *p_tab= *(p_tab + 2);// id : tab[0] , adress : 1004 , valeur : 5 ;


}
