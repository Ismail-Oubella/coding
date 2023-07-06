#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} node;

class set_int
{
    int N;
    node *tab;

public:
    set_int();
    set_int(set_int &);
    ~set_int();
    int appartient(int);
    void ajouter(int);
    int car();
    void display();
};

set_int ::set_int()
{
    tab = NULL;
    N = 0;
}

set_int ::~set_int() {
    node * temp= tab;
    node *supp = NULL;
    while (temp != NULL)
    {
        supp = temp;
        temp = temp->next;
        delete supp;
    }
}

set_int ::set_int(set_int &A)
{
    A.N = N;
    node *temp = A.tab;
    tab = NULL;
    node *element;
    while (temp != NULL)
    {
        element = new node;
        element->data = temp->data;
        element->next = tab;
        tab = element;
        temp = temp->next;
    }
}

int set_int::appartient(int a)
{
    node *temp = tab;
    while(temp != NULL){
        if(temp->data == a){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void set_int::ajouter(int a)
{
    
}

int set_int ::car()
{
    return N;
}

void set_int ::display()
{
    cout << "THis Is The Full Arr" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Elemeent Number " << i << " is : " << tab[i] << endl;
    }
}

int main()
{
    int n;
    cout << "Give the max : " << endl;
    cin >> n;
    set_int A(n);

    int number;

    cout << "donner le nombre d'elemenets que vous voulez siasir " << endl;
    cin >> number;
    int element;

    for (int i = 0; i < number; i++)
    {
        cout << "Element number " << i << " : " << endl;
        cin >> element;
        A.ajouter(element);
    }

    int found;

    cout << "Donnez l'elemeent a cherche : " << endl;
    cin >> found;

    if (A.appartient(found) == 1)
    {
        cout << found << " appartient" << endl;
    }
    else
    {
        cout << found << " non appartient" << endl;
    }

    cout << "Number of elements is " << A.car() << endl;

    cout << "Give a number to the arr : " << endl;
    cin >> element;

    A.ajouter(element);
    A.display();
    return 0;
}