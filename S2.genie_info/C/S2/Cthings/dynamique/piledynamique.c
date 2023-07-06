#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct list
{
    int val;
    struct list *next;
} list;

typedef list *pile;

typedef struct liste
{
    int val;
    struct liste *next;
} liste;

typedef struct
{
    liste *tete;
    liste *queue;
} file;

file initialis(file new)
{
    new.tete = NULL;
    new.queue = NULL;
    return new;
}


void emfilerr(file f, int val)
{
    liste *new = (liste *)malloc(sizeof(liste));
    new->val = val;
    new->next = NULL;
    if (f.queue == NULL)
    {
        f.tete = f.queue = new;
    }
    else
    {
        f.queue->next = new;
        f.queue = new;
    }
}


int defiler(file *f)
{
    int i;
    if (f->tete == NULL)
    {
        exit(-1);
    }
    i = f->tete->val;
    liste *supp = f->tete;
    f->tete = f->tete->next;
    if (f->tete == NULL)
    {
        f->queue = NULL;
    }
    free(supp);
    return i;
}


pile empiler(pile p, int val)
{
    list *new = (list *)malloc(sizeof(list));
    new->next = p;
    new->val = val;
    p = new;
    return p;
}

pile depiler(pile p, int *x)
{
    if (p == NULL)
        exit(0);
    *x = p->val;
    list *supp = p;
    p = p->next;
    free(supp);
    return p;
}

pile cree_pile(int n)
{
    pile p = NULL;
    int val;
    for (int i = 0; i < n; i++)
    {
        printf("val: \t");
        scanf("%d", &val);
        p = empiler(p, val);
        printf("\n");
    }
    return p;
}

pile test(pile *p1, pile p2){
    int x;
    file f=initialis(f);
    while (*p1 != NULL)
    {
        *p1 = depiler(*p1, &x);
        p2=empiler(p2, x);
    }
    while (p2 != NULL)
    {
        depiler(p2, &x);
        emfilerr(f,x);
    }
    while(f.tete!= NULL){
        x=defiler(&f);
        if(x%2==0)
        p2=empiler(p2, x);
        else 
        *p1=empiler(*p1,x);
    }
    return p2;
}

void dispaly(pile p)
{
    pile temp = p;
    int x;
    while (temp != NULL)
    {
        temp = depiler(temp, &x);
        printf("val =\t%d\n", x);
    }
}

void main()
{
    pile p = NULL;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    p = cree_pile(n);
    dispaly(p);
    pile pp=NULL;
    pp=test(&p,pp);
    printf("dispaly p intial\n");
    dispaly(p);
    printf("dispaly pp \n");
    dispaly(pp);
}
