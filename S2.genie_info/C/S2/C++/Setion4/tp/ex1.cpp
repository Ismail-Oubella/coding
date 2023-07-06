#include <iostream>
#include <cmath>
using namespace std;

class comp
{
    float Re;
    float Img;

public:
    comp(float, float);
    void display();
    float module();
    comp conjugue();
    comp operator+(comp);
    comp operator+(double);
    comp operator*(comp);
    comp operator*(double);
};

comp ::comp(float x = 0, float y = 0)
{
    Re = x;
    Img = y;
}

float comp ::module() { return sqrt(Re * Re + Img * Img); }

comp comp ::conjugue()
{
    comp test;
    test.Re = Re;
    test.Img = -Img;
    return test;
}

comp comp ::operator+(const comp temp)
{
    comp test;
    test.Re = Re + temp.Re;
    test.Img = Img + temp.Img;
    return test;
}

comp comp ::operator+(double temp)
{
    comp test;
    test.Re = Re + temp;
    test.Img = Img;
    return test;
}

comp comp ::operator*(const comp temp)
{
    comp test;
    test.Re = (Re * temp.Re) - (Img * temp.Img);
    test.Img = (Re * temp.Img) + (Img * temp.Re);
    return test;
}

comp comp ::operator*(double temp)
{
    comp test;
    test.Re = Re * temp;
    test.Img = Img * temp;
    return test;
}

void comp ::display() { cout << "This Is Your Number (" << Re << " + (" << Img << ")i) ;" << endl; }

int main()
{
    comp A;
    A.display();
    comp B(5, 9);
    B.display();
    double num = 10;

    cout << "The Modelu of your point is : " << A.module() << endl;
    cout << "The Modelu of your point is : " << B.module() << endl;

    cout << "The Conjugue of your point is : " << endl;
    (B.conjugue()).display();

    cout << " A + B = " << endl;

    (A + B).display();

    cout << " A + Num = " << endl;

    (A + num).display();

    cout << " A * B = " << endl;

    (A * B).display();

    cout << " A * Num = " << endl;

    (A * num).display();

    return 0;
}