#include <iostream>

using namespace std;

class vecteur3d
{
    float x, y, z;

public:
    vecteur3d(float, float, float);
    void display();
    vecteur3d somme3d(vecteur3d);
    float produitScalaire(vecteur3d);
};

vecteur3d::vecteur3d(float a = 0, float b = 0, float c = 0)
{
    x = a;
    y = b;
    z = c;
}

vecteur3d vecteur3d ::somme3d(vecteur3d U)
{
    vecteur3d V;
    V.x = this->x + U.x;
    V.y = this->y + U.y;
    V.z = this->z + U.z;
    return V;
}

float vecteur3d ::produitScalaire(vecteur3d U) { return this->x * U.x + this->y * U.y + this->z * U.z; }

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

    vecteur3d E = A.somme3d(D);
    E.display();

    cout << "produitScalaire E *B = " << E.produitScalaire(B) << endl;
    return 0;
}