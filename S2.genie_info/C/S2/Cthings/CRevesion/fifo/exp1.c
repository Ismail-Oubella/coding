#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef struct {
    int tab[N], tete, queue;
} file;

file initialisation(){
    file f;
    f.tete = f.queue = 0;
    return f;
}

int est_vide(file f) { return f.tete == f.queue; }

int est_plein(file f) { return f.queue == N; }

file enfiler(file f, int e){
    if(est_plein(f)==1){
        printf("Impossible Insertion!");
    }
   else
   {
        f.tab[f.queue] = e;
        (f.queue)++;
   }
    return f;
}

file defiler(file f, int * e){
    if(est_vide(f)==1){
        printf("Impossible Suppression!");
    }
    else{
        *e = f.tab[f.tete];
        (f.tete)++;
    }
    return f;
}

