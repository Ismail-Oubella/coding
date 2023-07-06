#include<stdio.h>
#include<stdlib.h>

#define d_max 7

typedef struct {
    int tab[d_max], sommet;
} pile;

pile initialisation(){ //? Pile initialisation
    pile p;
    p.sommet = -1;
    return p;
}

int est_vide(pile p){ //? Checking if the pile is empty or not
    if(p.sommet==-1)
        return 1;
    return 0;
}

pile empiler(pile p, int e){
    if(p.sommet==d_max-1){ //? Check if the pile has more espace to fill it, if not the programm exit with a message;
        printf("Pile is Full!");
        exit(-1);
    }
    (p.sommet)++; //? first we incrument the head of the pile , then we fill it with the value given
    p.tab[p.sommet] = e;
    return p;
}


int depiler(pile p){
    int x;
    if(est_vide(p)==1){
        printf("Empty Pile!");
        exit(-1);
    }
    x = p.tab[p.sommet];
    p.sommet--;
    return x;
}

