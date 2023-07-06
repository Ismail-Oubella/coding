#include<stdio.h>
int main(){
    
    int nombre1, nombre2, rest;
    char ch;

    printf("Ce programme permet de calculer la somme, la division, la soustraction et la multiplication de deux nombres.\n");

    printf("Donnez un de ces operations (+,-,* ou /): \n");
    scanf("%c",&ch);
    
    printf("Donnez le premier nombre: \n");
    scanf("%d",&nombre1);

    printf("Donnez le deuxieme nombre: \n");
    scanf("%d",&nombre2);


    switch(ch)
    {
        case '+': rest=nombre1+nombre2;
                  printf("%d%c%d=%d",nombre1,ch,nombre2,rest);
                  break;

        case '-': rest=nombre1-nombre2;
                  printf("%d%c%d=%d",nombre1,ch,nombre2,rest);
                  break;

        case '*': rest=nombre1*nombre2;
                  printf("%d%c%d=%d",nombre1,ch,nombre2,rest);
                  ;break;

        case '/': 
                if(nombre2 != 0){
                   rest=nombre1/nombre2;
                   printf("%d%c%d=%d",nombre1,ch,nombre2,rest);
                  
                }

                else{
                    printf("On peut pas diviser sur 0.");
                }
                break;

        default: printf("Cet operation est invalide.");
    }
    

    return 0;
    
}
