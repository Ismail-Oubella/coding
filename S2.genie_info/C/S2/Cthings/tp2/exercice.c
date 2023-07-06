#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ls
{
    int data;
    struct ls *next;
    struct ls *prev;
} ls;

int taille(ls *list)
{
    ls *temp = list;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    free(temp);
    return i;
}

ls *gotopos(ls *list, int n)
{
    ls *temp = list;
    for (int i = 1; i < n; i++)
    {
        temp = temp->next;
    }
    return temp;
}

ls *initialis()
{
    ls *new = (ls *)malloc(sizeof(ls));
    printf("Enter the data in the ls: ");
    scanf("%d", &new->data);
    new->next = NULL;
    new->prev = NULL;
    return new;
}

ls *insert_ls(ls *list)
{
    ls *new = initialis();
    if (list == NULL)
    {
        list = new;
    }
    else
    {
        ls *temp = gotopos(list, taille(list));
        temp->next = new;
        new->prev = temp;
    }
    return list;
}

ls *create_lis(ls *list)
{
    list = NULL;
    int n;
error:
    printf("Enter the n of data in the ls: ");
    scanf("%d", &n);
    if (n < 1)
        goto error;
    for (int i = 0; i < n; i++)
    {
        list = insert_ls(list);
    }
    return list;
}

ls *insert_pos(ls *list)
{
    int n;
error:
    printf("Size of list is %d, donc choisissez une position i tq (1 =< i <= size+1) :", taille(list));
    scanf("%d", &n);
    if (n < 1 || n > taille(list) + 1)
        goto error;
    ls *new = initialis();
    if (n == 1)
    {
        new->next = list;
        list->prev = new;
        list = new;
    }
    else
    {
        ls *temp = list;
        if (n == taille(list) + 1)
        {
            temp = gotopos(list, taille(list));
            temp->next = new;
            new->prev = temp;
        }
        else
        {
            temp = gotopos(list, n);
            new->next = temp;
            new->prev = temp->prev;
            temp->prev->next = new;
            temp->prev = new;
        }
    }
    return list;
}

ls *delete(ls *list)
{
    int n;
    printf("Donnez un max tel que every i <= max va etre supprime de list :");
    scanf("%d", &n);
    ls *temp = list;
    ls *supp = NULL;
    while (temp != NULL)
    {
        if (temp->data <= n)
        {
            supp = temp;
            if (temp->prev == NULL)
            {
                temp = temp->next;
                if (temp == NULL)
                {
                    return NULL;
                }
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
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
            }
            free(supp);
        }
        else
        {
            temp = temp->next;
        }
        supp = NULL;
    }
    free(temp);
    free(supp);
    return list;
}

void echange(ls *list)
{
    int p, q;
error:
    printf("Entrer les deux positions p et q tq (p != q , p,q > 0)pour l'inverser leurs donnes, donnant que la taille de list est %d :\n", taille(list));
    printf("p :\t");
    scanf("%d", &p);
    printf("q :\t");
    scanf("%d", &q);
    if (p == q || p < 0 || q < 0 || p > taille(list) || q > taille(list))
        goto error;
    int i;
    ls *temp = gotopos(list, p);
    ls *new = gotopos(list, q);
    i = temp->data;
    temp->data = new->data;
    new->data = i;
}

ls *assist(ls *list, int i)
{
    ls *new = (ls *)malloc(sizeof(ls));
    new->data = i;
    new->next = NULL;
    new->prev = NULL;
    if (list == NULL)
    {
        list = new;
    }
    else
    {
        ls *temp = gotopos(list, taille(list));
        temp->next = new;
        new->prev = temp;
    }
    return list;
}

ls *inverser(ls *list)
{
    ls *temp = gotopos(list, taille(list));
    ls *new = NULL;
    while (temp != NULL)
    {
        new = assist(new, temp->data);
        temp = temp->prev;
    }
    return new;
}

void trie(ls *list)
{
    ls *temp = NULL;
    int k;
    int n;
    do
    {
        k = 0;
        temp = list;
        while (temp->next != NULL)
        {
            if (temp->data > temp->next->data)
            {
                n = temp->next->data;
                temp->next->data = temp->data;
                temp->data = n;
                k++;
            }
            temp = temp->next;
        }
    } while (k != 0);
}

ls *insert_order(ls *list)
{
    ls *new = initialis();
    if (list == NULL)
    {
        return new;
    }
    int n=0;
    ls *temp = list;
    for (int i = 1; i <= taille(list); i++)
    {
        if (new->data < temp->data)
        {
            n++;
            if (i == 1)
            {
                new->next = list;
                list->prev = new;
                list = new;
            }

            else
            {
                temp = gotopos(list, i);
                new->next = temp;
                new->prev = temp->prev;
                temp->prev->next = new;
                temp->prev = new;
            }
            break;
        }
        temp = temp->next;
    }
    if (n==0)
    {
        temp = gotopos(list, taille(list));
        temp->next = new;
        new->prev = temp;
    }
    return list;
}

void display(ls *list)
{
    if (list == NULL)
    {
        printf("Your list is empty ! \n");
        exit(1);
    }
    int i = 1;
    ls *temp = list;
    while (temp != NULL)
    {
        printf("value %d : %d\n", i++, temp->data);
        temp = temp->next;
    }
}

void display_v1(ls *list)
{
    if (list == NULL)
    {
        printf("Your list is empty ! \n");
        exit(1);
    }
    int i = taille(list);
    ls *temp = gotopos(list, taille(list));
    while (temp != NULL)
    {
        printf("value %d : %d\n", i--, temp->data);
        temp = temp->prev;
    }
}

void main()
{
    ls *list = create_lis(list);
    display(list);
    printf("\n###################################\n");
    list = insert_pos(list);
    printf("List left to right: \n");
    display(list);
    printf("\n###################################\n");
    printf("List right to left: \n");
    display_v1(list);
    printf("\n###################################\n");
    list = delete (list);
    display(list);
    printf("\n###################################\n");
    echange(list);
    display(list);
    printf("\n###################################\n");
    printf("Inverser list: \n");
    ls *inv = inverser(list);
    display(inv);
    printf("\n###################################\n");
    printf("Trie list: \n");
    trie(list);
    display(list);
    printf("\n###################################\n");
    list=insert_order(list);
    printf("\nDisplay after : \n");
    display(list);
}