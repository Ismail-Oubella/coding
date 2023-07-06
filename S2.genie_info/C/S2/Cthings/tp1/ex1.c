#include <stdio.h>
#include <stdlib.h>

typedef struct ls
{
    int n;
    struct ls *next;
} ls;

typedef struct
{
    ls *pair;
    ls *impair;
} str;

ls *cree_vide()
{
    ls *temp = (ls *)malloc(sizeof(ls));
    printf("i (N) =>\t");
    scanf("%d", &temp->n);
    temp->next = NULL;
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
    ls *new = cree_vide();
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

ls *insert_pos(ls *list)
{
    ls *new = cree_vide();
    ls *temp = list;
    int pos, size = taille(list);

    printf("Your list contains %d items !\n", size);

    do
    {
        printf("Insert position =>\t");
        scanf("%d", &pos);

    } while (pos < 1 || pos > size + 1);

    if (list == NULL)
    {
        list = new;
    }

    else
    {
        if (pos == 1)
        {
            new->next = list;
            list = new;
        }

        else
        {

            if (pos == size + 1)
            {
                temp = gotopos(temp, size);
                temp->next = new;
            }

            else
            {
                temp = gotopos(temp, pos - 1);
                new->next = temp->next;
                temp->next = new;
            }
        }
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
        if (temp->n > 15)
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

void trie(ls *list)
{
    ls *temp = NULL;
    int i, n;
    if (list == NULL)
    {
        printf("\nEmpty list\n");
        exit(1);
    }
    do
    {
        temp = list;
        i = 0;
        while (temp->next != NULL)
        {
            if (temp->n > temp->next->n)
            {
                n = temp->n;
                temp->n = temp->next->n;
                temp->next->n = n;
                i++;
            }
            temp = temp->next;
        }
    } while (i != 0);
}

ls *insert_finii(ls *list, int i)
{

    ls *new = (ls *)malloc(sizeof(ls));
    new->n = i;
    new->next = NULL;

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

str *natur(ls *list)
{
    str *nature = (str *)malloc(sizeof(str));
    nature->pair = NULL;
    nature->impair = NULL;
    ls *temp = list;
    while (temp != NULL)
    {
        if (temp->n % 2 == 0)
        {
            nature->pair = insert_finii(nature->pair, temp->n);
        }
        else
        {
            nature->impair = insert_finii(nature->impair, temp->n);
        }
        temp = temp->next;
    }
    return nature;
}

void affichge(ls *list)
{
    ls *temp = list;
    int i = 0;
    if (list == NULL)
    {
        printf("Your list is empty!\n");
    }
    else
    {
        printf("Affichage de list : \n");
        while (temp != NULL)
        {
            printf("i (case n=%d)=>\t%d\n", i, temp->n);
            i++;
            temp = temp->next;
        }
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
        list = insert_fin(list);
    }
    affichge(list);

    printf("\n==================================\n");

    list = insert_pos(list);
    affichge(list);

    printf("\n==================================\n");

    list = deletesupr(list);
    affichge(list);

    printf("\n==================================\n");

    trie(list);
    affichge(list);

    printf("\n==================================\n");
    str *nature = natur(list);

    printf("List des paires : \n");
    affichge(nature->pair);

    printf("\n**********************************\n");

    printf("List des impaires : \n");
    affichge(nature->impair);
}
