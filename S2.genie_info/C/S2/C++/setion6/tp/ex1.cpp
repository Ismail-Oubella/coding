#include <iostream>
#include<cmath>
using namespace std;

class point
{
    float x, y;

public:
    void initialis(float, float);
    void affiche();
    float abs();
    float ord();
};

void point::initialis(float abs = 0, float ord = 0)
{
    x = abs;
    y = ord;
}

float point ::abs() { return x; }
float point ::ord() { return y; }

void point ::affiche() { cout << "This Is Your Point : (" << x << ", " << y << ")" << endl; }

class pointb : public point
{
public:
    pointb(float, float);
    float rho();
};

pointb::pointb(float abs, float ord)
{
    initialis(abs, ord);
}

float pointb::rho() { return sqrt(abs() * abs() + ord() * ord()); }



