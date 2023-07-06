#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

typedef struct
{
    char tab[N];
    int tete;
} pile;



pile *initialisation()
{
    pile *new = (pile *)malloc(sizeof(pile));
    new->tete = -1;
    return new;
}

void empiler(pile *p, char *name)
{
    int length = strlen(name);
    if (length > 20)
    {
        printf("Your String Contains More Than 20 Chars, Insert Less !\n");
    }
    else
    {
        p->tete = length - 1;
        strcpy(p->tab, name);
    }
}

char depiler(pile *p)
{
    if (p->tete == -1)
    {
        printf("Your Pile is Empty, From Depiler Function!\n");
        exit(-1);
    }
    char character = p->tab[p->tete];
    p->tete--;
    return character;
}

void empiler_char(pile *p, char character)
{
    if (p->tete == N - 1)
    {
        printf("Your Pill Is full, From empiler_char function!\n");
    }
    else
    {
        p->tete++;
        p->tab[p->tete] = character;
    }
}

void display(pile p)
{
    if (p.tete == -1)
    {
        printf("Your Pile Is Empty, From display Function!\n");
    }
    else
    {
        while (p.tete != -1)
        {
            printf("%c", depiler(&p));
        }
        printf("\n");
    }
}

int palindrome(pile p)
{
    if (p.tete == -1)
    {
        printf("Your Pile Is Empty, From palindrome Function!\n");
        return -1;
    }
    pile *temp = initialisation();
    int length = p.tete + 1;
    for (int i = 0; i < length / 2; i++)
    {
        empiler_char(temp, depiler(&p));
    }
    if (length % 2 != 0)
    {
        depiler(&p);
    }
    length = p.tete + 1;
    for (int i = 0; i < length; i++)
    {
        if (p.tab[p.tete] != temp->tab[temp->tete])
        {
            printf("Its not A Palindrome!\n");
            return 0;
        }
        depiler(temp);
        depiler(&p);
    }
    printf("It is Plalindrome!\n");
    return 1;
}

void main()
{
    pile *p = initialisation();
    empiler(p, "mohammed");
    display(*p);
    palindrome(*p);
    empiler(p, "aziza");
    display(*p);
    palindrome(*p);
    free(p);
}