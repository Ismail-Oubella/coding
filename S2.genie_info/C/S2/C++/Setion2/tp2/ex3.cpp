#include <iostream>
#include <cmath>

using namespace std;

class vecteur3d
{
    float x, y, z;

public:
    vecteur3d(float, float, float);
    void display();
    vecteur3d normeMax(vecteur3d);
    float Norme();
};

vecteur3d::vecteur3d(float a = 0, float b = 0, float c = 0)
{
    x = a;
    y = b;
    z = c;
}

float vecteur3d::Norme()
{
    return sqrt(x * x + y * y + z * z);
}

vecteur3d vecteur3d ::normeMax(vecteur3d U)
{
    if (this->Norme() > U.Norme())
    {
        return *this;
    }
    return U;
}

void vecteur3d::display()
{
    cout << "Your point coords are (" << x << "," << y << "," << z << ")" << endl;
}

int main()
{
    int n;
    vecteur3d A;
    vecteur3d B(2);
    vecteur3d C(3, 4);
    vecteur3d D(5, 6, 7);
    A.display();
    D.display();

    vecteur3d max = A.normeMax(D);
    max.display();
    return 0;
}