#include <stdio.h>
#include <stdlib.h>

#define N 40

typedef struct
{
    int tab[N];
    int tete;
    int queue;
} file;

file *initialis()
{
    file *f = (file *)malloc(sizeof(file));
    f->tete = 0;
    f->queue = 0;
    return f;
}

void emfiler(file *f, int i)
{
    if (f->queue >= N)
        exit(0);

    f->tab[f->queue] = i;
    f->queue++;
}

int defiler(file *f)
{
    if (f->queue == f->tete)
        exit(0);
    int i;
    i = f->tab[f->tete];
    f->tete++;
    return i;
}

int cmp(file f1, file f2)
{
    if (f1.tab[f1.tete] >= f2.tab[f2.tete])
        return 1;
    else
        return 0;
}

void emfilerdef(file *f1, file *f2)
{
    emfiler(f1, defiler(f2));
}

file *cree_file(int n)
{
    file *f = initialis();
    int val;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value : \t");
        scanf("%d", &val);
        emfiler(f, val);
    }
    return f;
}

void affichage(file f)
{
    int i;
    while (f.queue != f.tete)
    {
        printf(" the value : %d\t", defiler(&f));
    }
    printf("\n");
}

void trie(file f1, file *f2)
{
    int n;
    file *f3 = initialis();
    while (f1.queue != f1.tete)
    {
        emfiler(f3, defiler(&f1));
        n = f1.queue - f1.tete;
        for (int i = 0; i < n; i++)
        { 
            if (cmp(f1, *f3) == 0)
            {
                emfiler(&f1, defiler(f3));
                emfiler(f3, defiler(&f1));
            }
            else
            {
                emfiler(&f1, defiler(&f1));
            }
        }
        emfiler(f2, defiler(f3));
    }
    free(f3);
}

void main()
{
    int n;
again:
    printf("entre nombre des elements : \t");
    if (n > N)
        goto again;
    scanf("%d", &n);
    file *f = cree_file(n);
    affichage(*f);
    file *f2 = initialis();

    printf("\nFile trie : \n");
    trie(*f, f2);
    affichage(*f2);
    free(f2);
    free(f);
}