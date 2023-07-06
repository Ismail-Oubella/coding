#include <iostream>
using namespace std;

class set_int
{
    struct node
    {
        int data;
        node *next;
        node(int data = 0, node *next = nullptr) : data(data), next(next) {}
    };
    node *head;
    int N;

public:
    set_int();
    set_int(set_int &);
    ~set_int();
    int appartient(int);
    void ajouter(int);
    int car();
    void display();
};

set_int::set_int()
{
    head = nullptr;
    N = 0;
}

set_int::~set_int()
{
    node *temp = head;
    while (head != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}

set_int::set_int(set_int &A)
{
    head = nullptr;
    N = A.N;
    node *temp = A.head;
    while (temp != nullptr)
    {
        ajouter(temp->data);
        temp = temp->next;
    }
}

int set_int::appartient(int a)
{
    int k = 0;
    node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == a)
        {
            k++;
        }
        temp = temp->next;
    }
    return k;
}

void set_int::ajouter(int a)
{
    if (appartient(a) == 0)
    {
        node *temp = new node(a);
        temp->next = head;
        head = temp;
        N++;
    }
    else
    {
        cout << "Number is already in the list" << endl;
    }
}

int set_int::car()
{
    return N;
}

void set_int::display()
{
    cout << "This is the full list" << endl;
    node *temp = head;
    while (temp != nullptr)
    {
        cout << "Element is: " << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    set_int A;

    int number;
    cout << "How many elements do you want to add?" << endl;
    cin >> number;
    int element;
    for (int i = 0; i < number; i++)
    {
        cout << "Element number " << i << ": ";
        cin >> element;
        A.ajouter(element);
    }

    int found;
    cout << "Enter the element you want to search for: ";
    cin >> found;
    if (A.appartient(found) == 1)
    {
        cout << found << " is in the list" << endl;
    }
    else
    {
        cout << found << " is not in the list" << endl;
    }

    cout << "Number of elements is " << A.car() << endl;

    cout << "Enter a number to add to the list: ";
    cin >> element;
    A.ajouter(element);
    A.display();
    return 0;
}
