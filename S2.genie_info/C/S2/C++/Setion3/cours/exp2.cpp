#include <iostream>
using namespace std;

class vecteur3d
{
    float x, y, z;

public:
    vecteur3d(float, float, float);
    void display();
    friend int operator==(vecteur3d, vecteur3d);
    friend int operator!=(vecteur3d, vecteur3d);
    friend float operator*(vecteur3d, vecteur3d);
};

vecteur3d::vecteur3d(float a=0, float b=0, float c=0){
    x=a; y=b; z=c;
}

int operator==(vecteur3d A, vecteur3d B){
    return A.x == B.x && A.y == B.y && A.z == B.z;
}

int operator!=(vecteur3d A, vecteur3d B)
{
    return !(A == B);
}

float operator*(vecteur3d A, vecteur3d B){
    return A.x*B.x + A.y*B.y + A.z*B.z;
}

void vecteur3d:: display(){
    cout << "Coord Of Your Point : (" << x << "," << y << "," << z  << ")"<< endl;
}

int main()
{
    vecteur3d v1(1, 2, 3);
    vecteur3d v2(4, 5, 6);

    v1.display();
    v2.display();

    if (v1 == v2)
    {
        cout << "v1 is equal to v2" << endl;
    }
    else
    {
        cout << "v1 is not equal to v2" << endl;
    }

    if (v1 != v2)
    {
        cout << "v1 is not equal to v2" << endl;
    }
    else
    {
        cout << "v1 is equal to v2" << endl;
    }

    float dotProduct = v1 * v2;
    cout << "Dot product of v1 and v2 is: " << dotProduct << endl;

    return 0;
}
