#include <iostream>

using namespace std;

class vecteur3d
{
    float x, y, z;

public:
    vecteur3d(float, float, float);
    void display();
};

vecteur3d::vecteur3d(float a = 0, float b = 0, float c = 0){
    x = a;
    y = b;
    z = c;
}

void vecteur3d::display(){
    cout << "Your point coords are ("<<x<<"," << y<< "," << z << ")"<< endl;
}

int main() {
    int n;
    vecteur3d A;
    vecteur3d B(2);
    vecteur3d C(3, 4);
    vecteur3d D(5, 6, 7);
    A.display();
    B.display();
    C.display();
    D.display();
    return 0;
}