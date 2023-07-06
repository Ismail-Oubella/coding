#include <iostream>
using namespace std;

class point
{
    float x, y;

public:
    point(float, float);
    void deplace(point *);
    void affichage();
};
point::point(float absc, float ord)
{
    x = absc;
    y = ord;
}
void point::deplace(point *p)
{
    x = x * 0.74;
    y = y * 0.54;
}
void point::affichage()
{
    cout << x << " " << y << endl;
}
int main(int argc, char const *argv[])
{
    point a(4, 5);
    a.affichage();
    return 0;
}