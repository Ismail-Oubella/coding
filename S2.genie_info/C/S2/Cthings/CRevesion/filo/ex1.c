#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef struct{
    int tab[N], head;
} pile;

pile *initialiser(){
    pile *p = (pile *)malloc(sizeof(pile));
    p->head = -1;
    return p;
}

int pileVide(pile p){
    if(p.head==-1)
        return 1;
    return 0;
}

int depiler(pile *p){
    if(pileVide(*p)==1){
        printf("Empty Pile!");
        exti(-1);
    }
    int i = p->tab[p->head];
    (p->head)--;
    return i;
}

void empiler(pile *p, int e){
    if(p->head >= N-1 ){
        printf("Full Pile!");
        exit(-1);
    }
    (p->head)++;
    p->tab[p->head] = e;
}

int SommetPile(pile p) { return p.head; }