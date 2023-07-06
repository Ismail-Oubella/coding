#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pile
{
    char val;
    struct pile *next;
} pile;

pile *empiler(pile *head, char val)
{
    pile *new = (pile *)malloc(sizeof(pile));
    new->val = val;
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {

        new->next = head;
        head = new;
    }
    return head;
}

pile *initialis(pile *head)
{
    int n;
    char val;
error:
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);
    if (n < 1)
        goto error;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value char: ");
        getchar();
        scanf("%c", &val);
        head = empiler(head, val);
    }
    return head;
}

char depiler(pile **head, char *i)
{
    if (*head == NULL)
        exit(-1);
    char val;
    pile *supp = *head;
    *head = (*head)->next;
    val = supp->val;
    free(supp);
    *i = val;
    return val;
}

int pestvide(pile *head)
{
    int k = 0;
    pile *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        k++;
    }
    return k;
}

int palindrome(pile *head)
{
    pile *p = head;
    pile *p1 = NULL;
    int n = pestvide(p);
    int k = 0;
    char v;
    for (int i = 1; i <= n / 2; i++)
    {
        v = depiler(&p, &v);
        p1 = empiler(p1, v);
    }

    if (n % 2 != 0)
        v = depiler(&p, &v);

    while (pestvide(p) != 0)
    {
        if (depiler(&p, &v) != depiler(&p1, &v))
        {
            k++;
            break;
        }
    }
    if (k == 0)
        return 1;
    else
        return 0;
}

void display(pile *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    char ch;
    pile *temp = head;
    while (temp != NULL)
    {
        temp = depiler(&head, &ch);
        printf("%c ", ch);
    }
}

int main()
{
    pile *p = NULL;
    p = initialis(p);
    if (palindrome(p) == 1)
        printf("The string is palindrome\n");
    else 
        printf("The string is not palindrome\n"); 
}