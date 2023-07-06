#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

liste *cree_liste()
{
    liste *new = (liste *)malloc(sizeof(liste));
    printf("Donnez la valeur (int ) de val:\t");
    scanf("%d", &new->val);
    new->next = NULL;
    return new;
}

file emfiler(file f)
{
    liste *new = cree_liste();
    if (f.queue == NULL)
    {
        f.tete = f.queue = new;
    }
    else
    {
        f.queue->next = new;
        f.queue = new;
    }
    return f;
}

file *emfilerr(file *f, int val)
{
    liste *new = (liste *)malloc(sizeof(liste));
    new->val = val;
    new->next = NULL;
    if (f->queue == NULL)
    {
        f->tete = f->queue = new;
    }
    else
    {
        f->queue->next = new;
        f->queue = new;
    }
    return f;
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

int taille(file f)
{
    int i = 0;
    while (f.tete != NULL)
    {

        defiler(&f);

        i++;
    }

    return i;
}

file removefile(file f)
{
    int n = taille(f);
    file *temp = &f;
    int x;
    for (int i = 0; i < n; i++)
    {
        x = defiler(temp);
        if (x < 15)
        {
            temp = emfilerr(temp, x);
        }
    }
    return f;
}

void display(file *f)
{
    file *temp = f;
    while (temp->tete != NULL)
    {
        printf("val : %d\n", defiler(temp));
    }
}

void main()
{
    file f = initialis(f);
    int n;
    printf("donner le nombre des elements dans le file : \t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        f = emfiler(f);
    }
    printf("taille %d\n", taille(f));
    display(&f);
    // f = removefile(f);
    // display(&f);
}