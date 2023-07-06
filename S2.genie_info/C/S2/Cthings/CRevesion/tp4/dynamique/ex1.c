#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pile
{
    char data;
    struct pile *next;
} pile;

pile *initialisation()
{
    pile *new = (pile *)malloc(sizeof(pile));
    new->next = NULL;
    return new;
}

pile *empiler(pile *p, char val)
{
    pile *new = initialisation();
    new->data = val;
    if (p == NULL)
    {
        p = new;
    }
    else
    {
        new->next = p;
        p = new;
    }
    return p;
}

pile *depiler(pile *p, char *val)
{
    if (p == NULL)
        exit(0);
    *val = p->data;
    pile *supp = p;
    p = p->next;
    free(supp);
    return p;
}


void display(pile p)
{
    pile *temp = &p;
    if (temp == NULL)
    {
        printf("Your pile is Empty...!\n");
    }
    else
    {
        char val;
        while (temp->next != NULL)
        {
            printf("%c", val);
        }
        printf("\n");
    }
}

int length(pile p)
{
    pile *temp = &p;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

int palindrome(pile p)
{
    pile *current = &p;
    pile *temp = NULL;
    int taille = length(*current);
    char val;
    for (int i = 0; i < taille; i++)
    {
        depiler(current, &val);
        temp = empiler(temp, val);
    }
    if (taille % 2 != 0)
    {
        depiler(current, &val);
    }

    for (int i = 0; i < taille; i++)
    {
        char val_temp;
        char val_current;
        temp = depiler(temp, &val_temp);
        current = depiler(current, &val_current);
        if (val_temp != val_current)
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    pile *p = NULL;
    char val;
    for (int i = 0; i < 5; i++)
    {
        printf("Donner Votre nom, char by char....!\t");
        scanf(" %c", &val);
        p = empiler(p, val);
    }
    depiler(p, &val);
    free(p);
}
