#include<stdio.h>
#include<stdlib.h>

typedef struct ls
{
    int data;
    struct ls *next;
}ls;

ls *create(int i){
    ls *new = (ls *)malloc(sizeof(ls));
    new->data = i;
    new->next = NULL;
    return new;
}

int length(ls *list){
    int i=0;
    ls *temp = list;
    while (temp!=NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

ls *gotoPos(ls *list, int pos){
    if(list == NULL){
        printf("Empty List!");
        exit(-1);
    }
    else{
        ls *temp = list;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        return temp;
    }
}

ls *insertDebut(ls *list, int i){
    ls *new = create(i);
    if(list==NULL){
        return new;
    }
    else{
        new->next = list;
        list = new;
        return list;
    }
}

ls* insertFin(ls *list, int i){
    ls *new = create(i);
    ls *temp = list;
    if(list==NULL){
        list = new;
        return list;
    }
    temp = gotoPos(list, length(list));
    temp->next = new;
}

ls *insertPos(ls* list, int i, int pos){
    ls *new = create(i);
    if(list ==NULL){
        list = new;
        return list;
    }
    if (pos == 1){
        list = insertDebut(list, i);
    }
    else{
        if(pos == length(list)+1){
            list = insertFin(list, i);
        }
        else{
            ls *temp = gotoPos(list, pos);
            new->next = temp->next;
            temp->next = new;
        }
    }
    return list;
}

ls* insert(ls* list, int i){
    int n;
    do
    {
        printf("Hello, World!\n1-Insert En Debut\n2-Insert At End\n3-Insert In Position\n");
        scanf("%d", &n);
    } while (n > 3 || n < 1);
    switch (n)
    {
    case 1:
        list = insertDebut(list, i);
        break;
    case 2:
        list = insertFin(list, i);
        break;
    case 3:
        int pos;
        do
        {
            printf("Donnez la position! (length of this list is %d)", length(list));
            scanf("%d", &pos);
        } while (pos<1 || pos>length(list)+1);
        list = insertPos(list, i, pos);
        break;
    default:
        printf("No such Valide Value!");
        break;
    }
    return list;
}

int returnPos(ls *list, ls* temp){
    if(list == NULL || temp==NULL){
        return -1;
    }
    else{
        int i;
        for (i = 0; temp != list && temp!=NULL;i++){
            temp = temp->next;
        }
        return i;
    }
}

ls *deleteDe(ls *liste){
    ls *sup = liste;
    liste = liste->next;
    free(sup);
    return liste;
}

ls * delete(ls *liste, ls* temp){
    if(liste==NULL || temp==NULL){
        printf("Empty List!");
        return NULL;
    }
    temp = gotoPos(liste, returnPos(liste, temp) - 1);
    ls *sup = temp->next;
    temp->next = sup->next;
    free(sup);
    return temp;
}

ls *supp(ls *list){
    if(list == NULL){
        printf("Empty List!");
        exit(-1);
    }
    else{
        ls *temp = list;
        while(temp!=NULL){
            if(temp->data > 15){
                int pos = returnPos(list, temp);
                if (pos == 1)
                {
                    temp = deleteDe(temp);
                }
                else
                    temp=delete(list, temp);                
            }
            else
                temp = temp->next;
        }
    }
    return list;
}

void display(ls *list){
    printf("This is The list to be displayes!`n");
    ls *temp = list;
    int i = 0;
    while (temp != NULL)
    {
        printf("Data's Element %d: %d\n", i++, temp->data);
        temp = temp->next;
    }
}

int main(){

    ls *list = NULL;

    // Insert some elements into the list
    list = insert(list, 1);
    list = insert(list, 2);
    list = insert(list, 3);
    list = insert(list, 4);
    list = insert(list, 5);

    display(list);

    // Free the memory allocated for the list
    ls *curr = list;
    while(curr != NULL){
        ls *temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}
