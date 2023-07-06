#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dd;
    int MM;
    int yyyy;
} date;

typedef struct
{
    int id;
    char *nom;
    char *prenom;
    date dnaissance;
    float score;
    char *Distance;
    char *Termine;
} athlete;

typedef struct ls
{
    athlete ath;
    struct ls *next;
    struct ls *prev;
} ls;

typedef struct
{
    ls *shortc;
    ls *longc;
} dis;

ls *insert_new()
{
    ls *new = (ls *)malloc(sizeof(ls));
    new->next = NULL;
    new->prev = NULL;
    printf("Veuillez remplir les informations suivantes : \n");
    printf("le code identifiant : \t");
    scanf("%d", &new->ath.id);
    new->ath.nom = malloc(10);
    new->ath.prenom = malloc(10);
    printf("Nom :\t");
    scanf("%s", new->ath.nom);
    printf("Prenom :\t");
    scanf("%s", new->ath.prenom);

    printf("Date de naissance (dd/mm/yyyy) : \n");
dd:
    printf("dd : \t");
    scanf("%d", &new->ath.dnaissance.dd);
    if (new->ath.dnaissance.dd < 1 || new->ath.dnaissance.dd > 31)
        goto dd;

MM:
    printf("MM : \t");
    scanf("%d", &new->ath.dnaissance.MM);
    if (new->ath.dnaissance.MM < 1 || new->ath.dnaissance.MM > 12)
        goto MM;

yyyy:
    printf("yyyy : \t");
    scanf("%d", &new->ath.dnaissance.yyyy);
    if (new->ath.dnaissance.yyyy < 1950)
        goto yyyy;

dis:
    new->ath.Distance = malloc(6);
    printf("Distance  (400m ou 3000m) : \t");
    scanf("%s", new->ath.Distance);
    if (strcmp(new->ath.Distance, "400m") != 0 && strcmp(new->ath.Distance, "3000m") != 0)
        goto dis;

term:
    new->ath.Termine = malloc(6);
    printf("Termine  (oui ou non) : \t");
    scanf("%s", new->ath.Termine);
    if (strcmp(new->ath.Termine, "oui") != 0 && strcmp(new->ath.Termine, "non") != 0)
        goto term;

    printf("Score :\t");
    scanf("%f", &new->ath.score);
    return new;
}

ls *insert_list(ls *list)
{
    ls *new = insert_new();
    if (list == NULL)
    {
        list = new;
    }
    else
    {
        ls *temp = list;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
        new->prev = temp;
    }
    return list;
}

ls *delete_list(ls *list)
{
    if (list == NULL)
    {
        exit(1);
    }
    else
    {
        ls *temp = list;
        ls *supp = NULL;
        while (temp != NULL)
        {
            if (strcmp(temp->ath.Termine, "non") == 0)
            {
                supp = temp;
                if (temp->prev == NULL)
                {
                    temp = temp->next;
                    if (temp != NULL)
                        temp->prev = NULL;
                    list = temp;
                }
                else
                {
                    if (temp->next == NULL)
                    {
                        temp = temp->prev;
                        temp->next = NULL;
                    }
                    else
                    {
                        temp->prev->next = temp->next->prev;
                        temp->next->prev = temp->prev->next;
                        temp = temp->next;
                    }
                    free(supp);
                }
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    return list;
}

ls *insert_fin(ls temp, ls *ath)
{
    ls *new = (ls *)malloc(sizeof(ls));
    *new = temp;
    new->next = NULL;
    new->prev = NULL;
    if (ath == NULL)
    {
        ath = new;
    }
    else
    {
        ls *ptr = ath;
        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = new;
        new->prev = ptr;
    }
    return ath;
}

dis *athdis(ls *list)
{
    dis *new = (dis *)malloc(sizeof(dis));
    new->shortc = NULL;
    new->longc = NULL;
    if (list == NULL)
        exit(0);
    ls *temp = list;
    while (temp != NULL)
    {
        if (strcmp(temp->ath.Distance, "400m") == 0)
        {
            new->shortc = insert_fin(*temp, new->shortc);
        }
        else
        {
            new->longc = insert_fin(*temp, new->longc);
        }
        temp = temp->next;
    }
    return new;
}

ls *trie(ls *list)
{
    if (list == NULL || list->next == NULL)
        exit(1);
    ls *temp = NULL;
    athlete new;
    int i;
    do
    {
        temp = list;
        i = 0;
        while (temp->next != NULL)
        {
            if (temp->ath.score < temp->next->ath.score)
            {
                new = temp->ath;
                temp->ath = temp->next->ath;
                temp->next->ath = new;
                i++;
            }
            temp = temp->next;
        }

    } while (i != 0);
    return list;
}

void affichage(ls *list)
{
    if (list == NULL)
    {
        printf("Error ! List is NULL\n");
        exit(-1);
    }

    ls *temp = list;
    printf("Affichage de votre list :\n");
    while (temp != NULL)
    {
        printf("id : %d\t", temp->ath.id);
        printf("Nom : %s\t", temp->ath.nom);
        printf("Prenom : %s\n", temp->ath.prenom);
        printf("Date de naissance (dd/mm/yyyy) : \t");
        printf("(%d/%d/%d)\n", temp->ath.dnaissance.dd, temp->ath.dnaissance.MM, temp->ath.dnaissance.yyyy);
        printf("Distance : %s\n", temp->ath.Distance);
        printf("Termine : %s\n", temp->ath.Termine);
        printf("Score : %f\n", temp->ath.score);
        printf("\n**********************************\n");
        temp = temp->next;
    }
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
        list = insert_list(list);
        printf("\n**********************************\n");
    }

    printf("\n==================================\n");
    affichage(list);

    printf("\n==================================\n");
    list = delete_list(list);
    printf("Apres la suppression des athletes qui ont pas termine : \n");
    affichage(list);

    printf("\n==================================\n");
    ls *ath400 = NULL;
    ls *ath3000 = NULL;
    dis *course = athdis(list);

    printf("Liste d'athletes qui ont  termine la course de 400m : \n");
    affichage(course->shortc);

    printf("\n==================================\n");
    course->shortc = trie(course->shortc);
    printf("Les athletes qui ont termine la course de 400m en ordre decroissant : \n");
    affichage(course->shortc);

    printf("\n----------------------------------\n");

    printf("Liste d'athletes qui ont  termine la course de 3000m : \n");
    affichage(course->longc);
    
}