#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10

typedef struct 
{
    int tab[N], tete;
}pile;

typedef struct {
    int arr[N], head, queue;
} file;

pile * initialisation_pile(){
    pile *new = (pile *)malloc(sizeof(pile));
    new->tete = -1;
    return new;
}

file *initialisation_file()
{
    file *new = (file *)malloc(sizeof(file));
    new->head = new->queue = 0;
    return new;
}

void empiler(pile *p, int e){
    if(p->tete==N-1){
        printf("No Such Space, from empiler Function!\n");
    }
    else{
        p->tete++;
        p->tab[p->tete] = e;
    }
}

void enfiler(file *f, int e){
    if((f->queue+1)%N==f->head){
        printf("No Such Space, from enfiler Function!\n");
    }
    else{
        f->arr[f->queue] = e;
        f->queue = (f->queue + 1) % N;
    }
}

int depiler(pile *p){
    if(p->tete==-1){
        printf("Empty Pile, From depiler Function!\n");
        exit(-1);
    }
    int value = p->tab[p->tete];
    p->tete--;
    return value;
}

int defiler(file *f){
    if(f->head==f->queue)
    {
        printf("Empty file, From defiler Function!\n");
        exit(-1);
    }
    int value = f->arr[f->head];
    f->head = (f->head + 1) % N;
    return value;
}

void separate(pile *p1, pile *p2){
    file *f = initialisation_file();
    int length = p1->tete + 1;
    for (int i = 0; i < length; i++){
        empiler(p2, depiler(p1));
    }
    for (int i = 0; i < length; i++){
        enfiler(f, depiler(p2));
    }
    while(f->queue!=f->head){
        if(f->head%2==0)
            empiler(p2, defiler(f));
        else
            empiler(p1, defiler(f));
    }
}

void display_pile(pile p){
    if (p.tete == -1)
    {
        printf("Empty Pile, From display_pile Function!\n");
    }
    while(p.tete != -1){
        printf("%d ", depiler(&p));
    }
    printf("\n");
}

void display_file(file f){
    if (f.head == f.queue)
    {
        printf("Empty file, From dispaly_file Function!\n");
    }
    while (f.head != f.queue){
        printf("%d ", defiler(&f));
    }
    printf("\n");
}

void main(){
    pile *p1 = initialisation_pile();
    for (int i = 0; i < 10; i++){
        empiler(p1, i + 1);
    }
    display_pile(*p1);
    pile *p2 = initialisation_pile();
    separate(p1, p2);
    display_pile(*p1);
    display_pile(*p2);
    free(p1);
}