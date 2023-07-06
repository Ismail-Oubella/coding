#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int Temps;
    char *Distance;
    char *Termine;
} Score;

typedef struct
{
    int jours;
    int mois;
    int annee;
} date;

typedef struct
{
    int Code;
    char *Nom;
    char *Prenom;
    date DateNaissance;
    Score Competition;
} Athlete;

typedef struct ls
{
    Athlete joueur;
    struct ls *next;
} ls;

ls *athlete()
{
    ls *temp = (ls *)malloc(sizeof(ls));
    printf("Veuillez replissez ses informations : \n");
    printf("Code d'athlete :\t");
    scanf("%d", &temp->joueur.Code);
    temp->joueur.Nom = malloc(10);
    printf("Nom d'athlete :\t");
    scanf("%s", temp->joueur.Nom);
    temp->joueur.Prenom = malloc(10);
    printf("Prenom d'athlete :\t");
    scanf("%s", temp->joueur.Prenom);
    printf("Date de naissance (dd/MM/yyyy):\n");
dd:
    printf("dd :\t");
    scanf("%d", &temp->joueur.DateNaissance.jours);
    if (temp->joueur.DateNaissance.jours > 31 || temp->joueur.DateNaissance.jours < 1)
        goto dd;
MM:
    printf("MM :\t");
    scanf("%d", &temp->joueur.DateNaissance.mois);
    if (temp->joueur.DateNaissance.mois > 12 || temp->joueur.DateNaissance.mois < 1)
        goto MM;
yyyy:
    printf("yyyy :\t");
    scanf("%d", &temp->joueur.DateNaissance.annee);
    if (temp->joueur.DateNaissance.annee > 2020)
        goto yyyy;
    printf("Temps effectuée par l'athlete qui a termine la course :\t");
    scanf("%d", &temp->joueur.Competition.Temps);
    temp->joueur.Competition.Distance = malloc(6);
    printf("Distance de la course (200m ou 1500m) :\t");
    scanf("%s", temp->joueur.Competition.Distance);
    temp->joueur.Competition.Termine = malloc(4);
    printf("Athlète a termine la course oui ou non :\t");
    scanf("%s", temp->joueur.Competition.Termine);
    temp->next = NULL;
    printf("\n");
    return temp;
}

ls *gotopos(ls *list, int pos)
{
    ls *temp = list;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    return temp;
}

int taille(ls *list)
{
    ls *temp = list;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

int posnew(ls *list, ls *new)
{
    ls *temp = list;
    int i = 1;
    while (temp != new)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

ls *insert_fin(ls *list)
{
    ls *new = athlete();
    if (list == NULL)
    {
        list = new;
    }
    else
    {
        ls *temp = gotopos(list, taille(list));
        temp->next = new;
    }
    return list;
}

ls *deletesupr(ls *list)
{
    ls *temp = list;
    ls *supp = NULL;
    int i;
    while (temp != NULL)
    {
        if (strcmp(temp->joueur.Competition.Termine, "non") == 0)
        {
            i = posnew(list, temp);
            if (i == 1)
            {
                supp = temp;
                list = list->next;
                temp = list;
                free(supp);
            }
            else
            {
                temp = gotopos(list, i - 1);
                supp = temp->next;
                temp->next = supp->next;
                free(supp);
            }
        }
        else
        {
            temp = temp->next;
        }
    }
    return list;
}

ls *insert_finii(ls *list, ls *temp)
{

    ls *new = (ls *)malloc(sizeof(ls));
    *new = *temp;
    new->next = NULL;
    if (list == NULL)
    {
        list = new;
    }

    else
    {
        ls *ptr = gotopos(list, taille(list));
        ptr->next = new;
    }
    return list;
}

ls *run200m(ls *list)
{
    ls *temp = list;
    ls *at200 = NULL;
    while (temp != NULL)
    {
        if (strcmp(temp->joueur.Competition.Distance, "200m") == 0)
        {
            at200 = insert_finii(at200, temp);
        }

        temp = temp->next;
    }
    return at200;
}

void affichage(ls *list)
{
    ls *temp = list;
    if (list == NULL)
    {
        printf("Your list is empty !\n");
        exit(1);
    }
    while (temp != NULL)
    {
        printf("\n**********************************\n");
        printf("Nom : %s \tPrenom : %s \tCode : %d \nDate de naissance : %d/%d/%d \nTemps : %d \tDistance : %s \tCourse termine : %s \n",
               temp->joueur.Nom, temp->joueur.Prenom, temp->joueur.Code, temp->joueur.DateNaissance.jours, temp->joueur.DateNaissance.mois, temp->joueur.DateNaissance.annee, temp->joueur.Competition.Temps,
               temp->joueur.Competition.Distance, temp->joueur.Competition.Termine);
        temp = temp->next;
    }
}

ls *trierdec(ls *list)
{
    ls *temp = NULL;
    Athlete switchat;
    int i;

    ls *athtree = run200m(list);
    do
    {
        temp = athtree;
        i = 0;
        while (temp->next != NULL)
        {
            if (temp->joueur.Competition.Temps < temp->next->joueur.Competition.Temps)
            {
                switchat = temp->joueur;
                temp->joueur = temp->next->joueur;
                temp->next->joueur = switchat;
                i++;
            }
            temp = temp->next;
        }

    } while (i != 0);

    return athtree;
}

void main()
{
    int n;

again:
    printf("How long you want to ? ");
    scanf("%d", &n);
    if (n < 1)
        goto again;

    ls *list = NULL;
    for (int i = 0; i < n; i++)
    {
        list = insert_fin(list);
    }
    affichage(list);

    printf("\n==================================\n");

    list = deletesupr(list);
    affichage(list);

    printf("\n==================================\n");

    ls *athtree = trierdec(list);
    affichage(athtree);

    free(list);
    free(athtree);
}