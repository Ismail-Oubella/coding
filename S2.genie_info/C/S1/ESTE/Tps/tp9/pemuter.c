#include <stdio.h>
#include <string.h>
void main(){
char ch1[20]="BBBBBBBBBBBBBBB";
char ch2[20];
printf(" donner un mot : "); gets(ch2);
strncpy(ch1, ch2,3); puts(ch1);
strcpy(ch1, ch2); puts(ch1);
}
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    char *bjr=malloc(20);
    printf("but :\t");gets(bjr);
    void Inverser_ch(char *);
    Inverser_ch(bjr);
    printf("%s\n",bjr);
}

void permuter(char *a, char *b){
    char c;
    c=*a;
    *a=*b;
    *b=c;
}

void Inverser_ch(char *ch){
    int n=strlen(ch);
    for(int i=0; i<n/2; i++)
        permuter(ch+i,ch+n-1-i);
}
*/
