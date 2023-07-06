#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct
{
    int tab[N], tete, queue;
} file;

file *initialisation()
{
    file *new = (file *)malloc(sizeof(file));
    new->queue = new->tete = 0;
    return new;
}

void emfiler(file *f, int e)
{
    if ((f->queue + 1) % N == f->tete)
    {
        printf("Cannot insert Value %d into the file, It's Full!\n", e);
    }
    else
    {
        f->tab[f->queue] = e;
        f->queue = (f->queue + 1) % N;
    }
}

int defiler(file *f)
{
    if (f->queue == f->tete)
    {
        printf("Cannot Delete Value From File, It's Empty!\n");
        exit(-1);
    }
    int value = f->tab[f->tete];
    f->tete = (f->tete + 1) % N;
    return value;
}

void max(file *f, int maximum)
{
    if (f->queue == f->tete)
    {
        printf("It's Empty!\n");
    }
    else
    {
        int length;
        if (f->queue > f->tete)
        {
            length = f->queue - f->tete;
        }
        else
        {
            length = N - f->tete - f->queue;
        }
        for (int i = 0; i < length; i++)
        {
            int value = defiler(f);
            if (value < maximum)
            {
                emfiler(f, value);
            }
        }
    }
}

void display(file f)
{
    if (f.queue == f.tete)
    {
        printf("It's Empty!\n");
    }
    while (f.queue != f.tete)
    {
        printf("%d ", defiler(&f));
    }
    printf("\n");
}

void main()
{
    file *f = initialisation();
    for (int i = 0; i < 11; i++)
    {
        emfiler(f, i);
    }
    display(*f);
    max(f, 5);
    display(*f);
    free(f);
}
