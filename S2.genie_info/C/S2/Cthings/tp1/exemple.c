#include <stdio.h>
#include <stdlib.h>

typedef struct ls
{
    int n;
    struct ls *next;
} ls;

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
}
