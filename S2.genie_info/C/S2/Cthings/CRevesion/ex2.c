#include <stdio.h>
#include <stdlib.h>

typedef struct ls
{
    int data;
    struct ls *next;
    struct ls *prev;
} ls;

ls *create(int i)
{
    ls *new = (ls *)malloc(sizeof(ls));
    new->data = i;
    new->next = new->prev = NULL;
    return new;
};

ls *insertDe(ls *list, int i)
{
    ls *new = create(i);
    if (list == NULL)
    {
        list = new;
        return list;
    }
    new->next = list;
    list->prev = new;
    list = new;
    return list;
}

ls *insertFin(ls *list, int i)
{
    ls *new = create(i);
    if (list == NULL)
    {
        list = new;
        return list;
    }
    ls *temp = list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    new->prev = temp;
    temp->next = new;
    return list;
}

ls *gotoPos(ls *list, int pos)
{
    ls *temp = list;
    if (list == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    return temp;
}

ls *insertAvant(ls *list, int i, int pos)
{
    ls *new = (ls *)malloc(sizeof(ls));
    if (list == NULL)
    {
        list = new;
        return list;
    }
    ls *temp = gotoPos(list, pos);
    new->next = temp;
    new->prev = temp->prev;
    if(temp->prev=NULL){
        list = new;
    }
    else
    {
        temp->prev->next = new;
        temp->prev = new;
    }
    return list;
}

ls *insertApres(ls *list, int i, int pos){
    ls *new = (ls *)malloc(sizeof(ls));
    if (list == NULL)
    {
        list = new;
        return list;
    }
    ls *temp = gotoPos(list, pos);
    new->next = temp->next;
    new->prev = temp;
    if (temp->next!=NULL){
        temp->next->prev = new;
        temp->next = new;
    }
    return list;
}

ls *deleteDebut(ls *list){
    ls *sup = list;
    list = list->next;
    if(list ==NULL)
        return NULL;
    else{list->prev = NULL;}
    free(sup);
    return list;
}

ls *deleteFin(ls *list)
{
    if (list == NULL)
    {
        return NULL;
    }
    else if (list->next == NULL)
    {
        free(list);
        return NULL;
    }
    else
    {
        ls *temp = list;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        return list;
    }
}

ls *deletePos(ls *list, int pos){
    if (list == NULL || list->next == list->prev = NULL)
        return NULL;
    else {
        if()
    }
}