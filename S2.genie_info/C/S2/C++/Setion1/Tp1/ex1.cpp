#include <iostream>
using namespace std;

class point
{
    float x;
    float y;

public:
    point(float, float);
    void deplace(int);
    void display();
};

point ::point(float a = 0, float b = 0)
{
    x = a;
    y = b;
}

void point ::deplace(int d)
{
    x += d;
    y += d;
}

void point ::display()
{
    cout << "Les coordonnes de votre point est : (" << x << "," << y << ")" << endl;
}

int main() {
    point p;
    p.display();

    point q(2.3 , -1);
    q.display();

    int dx;
    cout <<"Donnez dx de point : " << endl;
    cin >> dx;

    q.deplace(dx);
    q.display();

    return 0;
}