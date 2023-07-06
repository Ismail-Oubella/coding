#include <iostream>
using namespace std;

class vecteur3d
{
    float x, y, z;

public:
    vecteur3d(float, float, float);
    int comparer(vecteur3d);
    void comparer(vecteur3d *, int *);
    void Rcomparer(vecteur3d &, int &);
    void display();
};

vecteur3d::vecteur3d(float a = 0, float b = 0, float c = 0)
{
    x = a;
    y = b;
    z = c;
}

int vecteur3d::comparer(vecteur3d U) { return U.x == x && U.y == y && U.z == z; }

void vecteur3d::comparer(vecteur3d *U, int *i) {*i = U->x == x && U->y == y && U->z == z;}

void vecteur3d::Rcomparer(vecteur3d &U, int &i) { i = U.x == x && U.y == y && U.z == z; }

void vecteur3d::display()
{
    cout << "Your point coords are (" << x << "," << y << "," << z << ")" << endl;
}

int main()
{
    vecteur3d A;
    vecteur3d B(2);
    vecteur3d C(3, 4);
    vecteur3d D(5, 6, 7);
    vecteur3d E(0, 0, 0);
    A.display();
    B.display();
    C.display();
    D.display();

    vecteur3d *table = new vecteur3d[5];
    table[0] = A;
    table[1] = B;
    table[2] = C;
    table[3] = D;
    table[4] = E;

    for (int i = 0; i < 5; i++)
    {
        if(table[0].comparer(table[i]) == 1){
            cout << "Coinside " << endl;
        }
        else {
            cout << "Non Coinside " << endl;
        }
    }

    cout << "Passage By Adress" << endl;

    int i;

    for (int j = 0; j < 5; j++)
    {
        table[0].comparer(&table[j], &i);
        if (i == 1)
        {
            cout << "Coinside " << endl;
        }
        else
        {
            cout << "Non Coinside " << endl;
        }
    }

    cout << "Passage By Ref" << endl;


    for (int j = 0; j < 5; j++)
    {
        table[0].Rcomparer(table[j], i);
        if (i == 1)
        {
            cout << "Coinside " << endl;
        }
        else
        {
            cout << "Non Coinside " << endl;
        }
    }

    delete table;

    return 0;
}

