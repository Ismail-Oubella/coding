#include <iostream>
#include <cmath>

using namespace std;

class Point
{
    float x;
    float y;

public:
    Point(float, float);
    void deplace(float, float);
    float abcisse();
    float ordonnee();
    void homothetie(float);
    void rotation(float);
    float rho();
    float theta();
};

float angle(float x, float y)
{
    float a = atan(fabs(y / x));
    if (x > 0 && y > 0)
        return a;
    if (x > 0 && y < 0)
        return -a;
    if (x < 0 && y > 0)
        return M_PI - a;
    else
        return M_PI - a;
}

Point::Point(float a, float b)
{
    x = a;
    y = b;
    cout << "x=" << x << "and y=" << y << endl;
}

void Point::deplace(float dx, float dy)
{
    x += dx;
    y += dy;
    cout << " after deplacing the point : x=" << x << "and y=" << y << endl;
}

float Point::abcisse()
{
    cout << x << "is the abcisse " << endl;
    return x;
}

float Point::ordonnee()
{
    cout << y << "is the abcisse " << endl;
    return y;
}

void Point ::homothetie(float hom)
{
    x *= hom;
    y *= hom;
    cout << " after homothetie the point with a rapport : x=" << x << "and y=" << y << endl;
}

float Point::theta()
{
    return angle(x, y);
}

float Point::rho()
{
    return sqrt(x * x + y * y);
}

void Point::rotation(float rot)
{
    float m = theta();
    m = rot + m;
    float r = rho();
    x = r * cos(m);
    y = r * sin(m);
    cout << " after retation the point : x=" << x << "and y=" << y << endl;
}

int main() {
    float a, b;
    cin >> a >> b;
    Point p1(a, b);
    p1.deplace(1,1);
    p1.homothetie(3);
    p1.rotation(2);
    return 0;
}