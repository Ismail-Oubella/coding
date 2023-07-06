#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct etd
{
    char nom[20];
    char prenom[20];
    float note;
} etd;
typedef struct elm
{
    struct elm *suivant;
    etd etud;
} elm;

elm *cree(etd E)
{
    elm *new;
    new = (elm *)malloc(sizeof(elm));
    strcpy(new->etud.nom, E.nom);
    strcpy(new->etud.prenom, E.prenom);
    new->etud.note = E.note;
    new->suivant = NULL;
    return new;
}

elm *insert_debut(elm *Lis, etd E)
{
    elm *new;
    new = cree(E);
    new->suivant = Lis;
    Lis = new;
    return Lis;
}

elm *cree_lst(int n)
{
    etd E;
    elm *lis = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s%f", E.nom, E.prenom, &E.note);
        lis = insert_debut(lis, E);
    }
    return lis;
}

void affiche(elm *lis)
{
    elm *temp = lis;
    while (temp != NULL)
    {
        printf("[%s\t%s\t%.2f]", temp->etud.nom, temp->etud.prenom, temp->etud.note);
        printf("\n");
        temp = temp->suivant;
    }
}

void affiche10(elm *lis)
{
    elm *temp = lis;
    while (temp != NULL)
    {
        if (temp->etud.note > 10)
            printf("[%s\t%s\t%.2f]", temp->etud.nom, temp->etud.prenom, temp->etud.note);
        printf("\n");
        temp = temp->suivant;
    }
}
void bonus(elm *lis)
{
    elm *temp = lis;
    while (temp != NULL)
    {
        if (temp->etud.note < 10)
            temp->etud.note += 1;
        else if (temp->etud.note <= 15)
            temp->etud.note += 0.5;
        temp = temp->suivant;
    }
}

void main()
{
    int n = 3;
    elm *lis = cree_lst(n);
    affiche(lis);
    bonus(lis);
    affiche(lis);
}
