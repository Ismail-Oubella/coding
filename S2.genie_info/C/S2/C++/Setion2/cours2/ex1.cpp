#include <iostream>
using namespace std;

class matrice;

class vect
{
    float vet[3];

public:
    vect(float, float, float);
    void display();
    friend vect prod(vect, matrice);
};

class matrice
{
    float mat[3][3];

public:
    matrice();
    friend vect prod(vect, matrice);
    void display();
};

vect::vect(float a = 0, float b = 0, float c = 0)
{
    vet[0] = a;
    vet[1] = b;
    vet[2] = c;
}

void vect ::display()
{
    cout << "Your point coords are (" << vet[0] << "," << vet[1] << "," << vet[2] << ")" << endl;
}

void matrice ::display()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Row : " << i << "Column : " << j << " -> " << mat[i][j] << endl;
        }
    }
}

matrice ::matrice()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = i + j;
        }
    }
}

vect prod(vect v, matrice m)
{
    vect p;
    float sum;
    for (int i = 0; i < 3; i++)
    {
        sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += m.mat[i][j] * v.vet[j];
        }
        p.vet[i] = sum;
    }
    return p;
}

int main()
{
    vect v(1, 2, 3);
    matrice m;
    m.display();
    v.display();

    prod(v, m).display();
}