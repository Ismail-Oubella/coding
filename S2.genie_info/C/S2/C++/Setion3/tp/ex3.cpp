#include <iostream>
using namespace std;

class set_int
{
    int N;
    int *tab;
    int max;

public:
    set_int(int);
    set_int(set_int &);
    ~set_int();
    int appartient(int);
    void ajouter(int);
    int car();
    void display();
};

set_int ::set_int(int a = 20)
{
    max = a;
    N = 0;
    tab = new int[max];
}

set_int ::~set_int() { delete[] tab; }

set_int ::set_int(set_int &A)
{
    A.max = max;
    A.N = N;
    tab = new int[max];
    for (int i = 0; i < max; i++)
    {
        tab[i] = A.tab[i];
    }
}

int set_int::appartient(int a)
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if (tab[i] == a)
        {
            return ++k;
        }
    }
    return k;
}

void set_int::ajouter(int a)
{
    if (N == max)
    {
        cout << "Your arr is full" << endl;
    }
    else
    {
        if(this->appartient(a) == 0)
        {
            tab[N] = a;
            N++;
        }
        else {
            cout << "Number is already in the arr" << endl;
        }
    }
}


int set_int :: car(){
    return N;
}

void set_int ::display(){
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
        cout << found <<" appartient" << endl;
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