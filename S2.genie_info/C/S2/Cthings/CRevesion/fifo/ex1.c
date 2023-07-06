#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct
{
    int tab[N], tete, queue;
} file;

file *initialisation()
{
    file *f = (file *)malloc(sizeof(file));
    f->queue = f->tete = 0;
    return f;
}

int fileVide(file f) { return f.tete == f.queue; }

void emfiler(file *f, int i)
{
    if (f->queue >= N)
        exit(0);

    f->tab[f->queue] = i;
    f->queue++;
}

int defiler(file *f)
{
    if (fileVide(*f) == 1)
    {
        printf("Suppression Impossible!");
    }
    else
    {
        int i = f->tab[f->tete];
        (f->tete)++;
        return i;
    }
}

int fileSommet(file f)
{
    if (fileVide(f) == 1)
    {
        printf("File Vide, Value returned is -1!");
        exit(-1);
    }
    return f.tab[f.tete];
}

int comparer(file f1, file f2) { return fileSommet(f1) >= fileSommet(f2); }

void trie(file *f1, file *f2)
{
    void display(file);
    file *temp = initialisation();
    while (f1->queue != f1->tete)
    {
        emfiler(temp, defiler(f1));
        int n = f1->queue - f1->tete;
        for (int i = 0; i < n; i++)
        {
            if (comparer(*f1, *temp) == 1)
            {
                emfiler(f1, defiler(temp));
                emfiler(temp, defiler(f1));
            }
            else
            {
                emfiler(f1, defiler(f1));
            }
        }
        emfiler(f2, defiler(temp));
    }
    free(temp);
}

void display(file f)
{
    int i = 0;
    while (f.queue != f.tete)
    {
        printf("Item Number %d: %d;\n", i++, defiler(&f));
    }
    printf("\n##################################################################\n");
}

void main()
{
    file *f = initialisation();
    for (int i = 0; i < 5; i++)
    {
        emfiler(f, i + 1);
    }
    printf("File Principal: \n;");
    display(*f);
    file *fl = initialisation();
    trie(f, fl);
    display(*fl);
    free(f);
    free(fl);
}