#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct abonne
{
    int num_tel;
    char *nom_abonne;
    char *adress;
    struct abonne *next;
    struct abonne *prev;
} abonne;

typedef struct zone
{
    int code, nb_abonnes;
    char *nom_zone;
    abonne *debut_abonne;
    abonne *fin_abonne;
    struct zone *next;
} Repertoire_telephone;

abonne *initialisation_abonne()
{
    abonne *temp = (abonne *)malloc(sizeof(abonne));
    if (temp == NULL)
    {
        printf("No Such Space To Create Abonne Element!\n");
        exit(-1);
    }
    temp->next = temp->prev = NULL;
    temp->nom_abonne = malloc(20);
    temp->adress = malloc(20);
    if (temp->nom_abonne == NULL || temp->adress == NULL)
    {
        printf("No Such Space To Create Abonne Element!\n");
        exit(-1);
    }
    return temp;
}

Repertoire_telephone *initialisation_rep(int code, char *nom)
{
    Repertoire_telephone *temp = (Repertoire_telephone *)malloc(sizeof(Repertoire_telephone));
    if (temp == NULL)
    {
        printf("No Such Space To Create Abonne Element!\n");
        exit(-1);
    }
    temp->nb_abonnes = 0;
    temp->nom_zone = malloc(20);
    strcpy(temp->nom_zone, nom);
    temp->code = code;
    temp->debut_abonne = temp->fin_abonne = NULL;
    temp->next = NULL;
    return temp;
}

int Ajouter_zone(Repertoire_telephone *list, int code, char *nom)
{

    Repertoire_telephone *new = initialisation_rep(code, nom);
    Repertoire_telephone *temp = list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    return 1;
    return -1;
}

int Ajouter_abonne(Repertoire_telephone *list, int num_tel, char *nom_abonne, char *adresse, int code_zone)
{
    if (list == NULL)
    {
        printf("Your List is Empty, From Ajouter_Abonne Function!\n");
        return -1;
    }
    abonne *new = initialisation_abonne();
    new->num_tel = num_tel;
    strcpy(new->nom_abonne, nom_abonne);
    strcpy(new->adress, adresse);
    Repertoire_telephone *temp = list;
    while (temp->code != code_zone && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Code Zone Not Found!\n");
        return -1;
    }
    if (temp->nb_abonnes == 0)
    {
        temp->debut_abonne = temp->fin_abonne = new;
        temp->nb_abonnes++;
        return 1;
    }
    else
    {
        temp->nb_abonnes++;
        abonne *try = temp->debut_abonne;
        while (try->next != NULL)
        {
            try = try->next;
        }
        try->next = new;
        new->prev = try;
        temp->fin_abonne = new;
        return 1;
    }
    return -1;
}

int Enregistrer_abonne(Repertoire_telephone *list, char *nom, int code_zone)
{
    if (list == NULL)
    {
        printf("Your List is Empty, From Energistrer_abonne Function!\n");
        return -1;
    }
    Repertoire_telephone *temp = list;
    while (temp->code != code_zone && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->debut_abonne == NULL)
    {
        printf("Code Zone Not Found!\n");
        return -1;
    }
    abonne *try = temp->debut_abonne;
    while (strcmp(try->nom_abonne, nom) != 0 && try != NULL)
    {
        try = try->next;
    }
    if (try == NULL)
    {
        printf("Subscriver Not Found!\n");
        return -1;
    }
    else
    {
        return try->num_tel;
    }
    return -1;
}

int Enlever_abonne(Repertoire_telephone *list, int numero)
{
    if (list == NULL)
    {
        printf("Your List is Empty, Form Enlever_abonne Function!\n");
        return -1;
    }
    Repertoire_telephone *temp = list;
    while (temp != NULL)
    {
        abonne *try = temp->debut_abonne;
        while (try != NULL)
        {
            if (try->num_tel == numero)
            {
                if (try == temp->debut_abonne)
                {
                    temp->debut_abonne = try->next;
                    if (temp->debut_abonne == NULL)
                    {
                        temp->fin_abonne == NULL;
                    }
                    else
                    {
                        temp->debut_abonne->prev = NULL;
                    }
                }
                else
                {
                    if (try == temp->fin_abonne)
                    {
                        try->prev->next = NULL;
                        temp->fin_abonne = try->prev;
                    }
                    else
                    {
                        try->next->prev = try->prev;
                        try->prev->next = try->next;
                    }
                }
                free(try->adress);
                free(try->nom_abonne);
                free(try);
                temp->nb_abonnes--;
                return 1;
            }
            try = try->next;
        }
        temp = temp->next;
    }
    printf("Number (%d) Not Found!\n", numero);
    return -1;
}



int Enlever_zone(Repertoire_telephone *list, int code_zone)
{
    if (list == NULL)
    {
        printf("Your List is Empty, Form Enlever_abonne Function!\n");
        return -1;
    }
    Repertoire_telephone *curr = list;
    Repertoire_telephone *previous = NULL;

    while (curr != NULL && curr->code != code_zone)
    {
        previous = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        printf("Zone Code Not Found!");
        return -1;
    }

    if (previous == NULL)
    {
        list = curr->next;
    }
    else
    {
        previous->next = curr->next;
    }
    abonne *head = curr->debut_abonne;
    while(head != NULL){
        abonne *next = head->next;
        free(head->adress);
        free(head->nom_abonne);
        head = next;
    }
    free(curr);
    return 1;
}

void display(Repertoire_telephone *list)
{
    if (list == NULL)
    {
        printf("List is empty, From display Function!\n");
        return;
    }
    Repertoire_telephone *temp = list;
    while (temp != NULL)
    {
        printf("Code: %d, Nom: %s, Nombre d'abonnes: %d\n", temp->code, temp->nom_zone, temp->nb_abonnes);
        abonne *try = temp->debut_abonne;
        while (try != NULL)
        {
            printf("\tNom de l'abonne: %s, Numero de telephone: %d, Adresse: %s\n", try->nom_abonne, try->num_tel, try->adress);
            try = try->next;
        }
        printf("\n");
        temp = temp->next;
    }
}

int main()
{
    Repertoire_telephone *list = initialisation_rep(0, "Zone 0");

    // Ajouter des zones
    printf("\n");
    printf("Ajouter des zones!");
    printf("\n##########################################################################\n");
    Ajouter_zone(list, 1, "Zone 1");
    Ajouter_zone(list, 2, "Zone 2");

    printf("Display List!");
    printf("\n##########################################################################\n");
    display(list);

    // Ajouter des abonnes
    printf("\n");

    printf("Ajouter des Abonnes!");
    printf("\n##########################################################################\n");
    Ajouter_abonne(list, 123456, "Alice", "Paris", 0);
    Ajouter_abonne(list, 789012, "Bob", "Lyon", 2);

    // Afficher le repertoire
    printf("\n");
    printf("Display List!");
    printf("\n##########################################################################\n");
    display(list);

    // Enregistrer un abonne
    printf("\n");

    printf("Enregestrer Un Abonne!");
    printf("\n##########################################################################\n");

    int num_tel = Enregistrer_abonne(list, "Alice", 1);
    printf("Le numero de telephone d'Alice est : %d\n", num_tel);

    // Enlever un abonne
    printf("\n");

    printf("Enlever Un Abonne!");
    printf("\n##########################################################################\n");

    int status = Enlever_abonne(list, 789012);
    if (status == 1)
    {
        printf("Abonne enleve avec succes.\n");
    }
    else
    {
        printf("Erreur lors de la suppression de l'abonne.\n");
    }

    // Afficher le repertoire mis a jour
    printf("\n");
    printf("Display List!");
    printf("\n##########################################################################\n");

    display(list);

    //Delete a Zone
    printf("\n");
    printf("Delete A Zone!");
    printf("\n##########################################################################\n");

    Enlever_zone(list, 1);

    //display
    printf("Display List!");
    printf("\n##########################################################################\n");

    display(list);

    free(list);
    return 0;
}
