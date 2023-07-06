#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_pile 6
#define max_assiettes 10

typedef struct
{
    int assiettes[max_assiettes], tete;
} assiette;

typedef struct
{
    int head, queue;
    assiette arr[max_pile];
} file;

file *initialisation_file()
{
    file *new = (file *)malloc(sizeof(file));
    new->head = new->queue = 0;
    return new;
}

void ajouter_pile(file *f, int e)
{
    if (e == 0)
    {
        printf("Cannto add pile with 0 assistes, from ajouter_pile function!\n");
    }
    else
    {
        if ((f->queue + 1) % max_pile == f->head)
        {
            printf("You already got max of piles, from emfiler function!\n");
        }
        else
        {
            f->arr[f->queue].tete = -1;
            for (int i = 0; i < e; i++)
            {
                f->arr[f->queue].tete++;
                f->arr[f->queue].assiettes[f->arr[f->queue].tete] = 1;
            }
            f->queue = (f->queue + 1) % max_pile;
        }
    }
}

void retirer_assiette(file *f)
{
    if (f->arr[f->head].tete == -1)
    {
        f->head = (f->head + 1) % max_pile;
    }

    if (f->head == f->queue)
    {
        printf("File empty, from retirer_assiette function!\n");
    }
    else
    {
        f->arr[f->head].assiettes[f->arr[f->head].tete] = 0;
        f->arr[f->head].tete--;
    }
}

int defiler(file *f)
{
    if (f->head == f->queue)
    {
        return -1;
    }
    int nb_assiettes = f->arr[f->head].tete + 1;
    while (f->arr[f->head].tete != -1)
    {
        retirer_assiette(f);
    }
    f->head = (f->head + 1) % max_pile;
    return nb_assiettes;
}

int add_assiette(file *f, int e)
{
    while ((f->queue + 1) % max_pile != f->head && e != 0)
    {
        if (e >= 10)
        {
            ajouter_pile(f, 10);
            e -= 10;
        }
        else
        {
            ajouter_pile(f, e);
            e = 0;
        }
    }
    if (e != 0)
    {
        file *temp = initialisation_file();
        while (f->head != f->queue && e != 0)
        {
            if (f->arr[f->head].tete == max_assiettes - 1)
            {
                ajouter_pile(temp, defiler(f));
            }
            else
            {
                int rest = max_assiettes - f->arr[f->head].tete - 1;
                if (e < rest)
                {
                    rest = e;
                    e = 0;
                }
                else
                {
                    e -= rest;
                }
                for (int j = 0; j < rest; j++)
                {
                    f->arr[f->head].tete++;
                    f->arr[f->head].assiettes[f->arr[f->head].tete] = 1;
                }
            }
        }
        int n;
        if (temp->queue > temp->head)
        {
            n = temp->queue - temp->head;
        }
        else
        {
            n = max_pile - temp->head - temp->queue;
        }
        for (int j = 0; j < n; j++)
        {
            ajouter_pile(f, defiler(temp));
        }
        free(temp);
    }
    return e;
}

int etat_before(file f){
    if(f.head==f.queue){
        return 50;
    }
    int count = 0;
    int i = 0;
    while (i < 5)
    {
        count += max_assiettes - f.arr[f.head].tete - 1;
        defiler(&f);
        i++;
    }
    return count;
}

void etat(file *f, int n){
    printf("Before, it still %d asseittes can be added!\n", etat_before(*f));
    printf("Number Of Assiettes au poubelle: %d\n", add_assiette(f, n));
    printf("After, it still %d asseittes can be added!\n", etat_before(*f));
}

void main()
{
    file *f = initialisation_file();
    etat(f, 60);

    printf("\n############################################################\n");

    for (int i = 0; i < 23; i++){
        retirer_assiette(f);
    }

    etat(f, 13);

    free(f);
}
