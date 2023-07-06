#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct
{
    int tab[N], sommet;
} pile;

pile *initialisation()
{
    pile *p = (pile *)malloc(sizeof(pile));
    p->sommet = -1;
    return p;
}

void empiler(pile *p, int e)
{
    if (p->sommet >= N - 1)
    {
        printf("Full Pile!");
    }
    else
    {
        (p->sommet)++;
        p->tab[p->sommet] = e;
    }
}

int depiler(pile *p)
{
    if (p->sommet == -1)
    {
        printf("Empty Pile!");
    }
    else
    {
        int i = p->tab[p->sommet];
        (p->sommet)--;
        return i;
    }
}

void copier(pile *p1, pile *p2)
{
    pile *temp = initialisation();
    for (int i = 0; i < N; i++)
    {
        if (p1->tab[p1->sommet] % 2 == 0)
        {
            empiler(temp, depiler(p1));
        }
        else
        {
            empiler(p2, depiler(p1));
        }
    }

    while (p2->sommet != -1)
    {
        empiler(p1, depiler(p2));
    }
    while (temp->sommet != -1)
    {
        empiler(p2, depiler(temp));
    }
}

void display(pile p)
{
    if (p.sommet == -1)
    {
        printf("There is no such value to be desplayed!");
    }
    else
    {
        int max = p.sommet;
        for (int i = 0; i <= max; i++)
        {
            printf("Item Number %d: %d\n", i, depiler(&p));
        }
    }
}

void main()
{
    pile *p = initialisation();
    for (int i = 0; i < N; i++)
    {
        empiler(p, i + 1);
    }
    display(*p);
    pile *pl = initialisation();
    copier(p, pl);
    printf("Display Pile P!\n");
    display(*p);
    printf("Display Pile Pl!\n");
    display(*pl);
}