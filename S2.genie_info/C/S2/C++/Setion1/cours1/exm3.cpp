#include <iostream>
using namespace std;

class point
{
    int x;
    int y;

public:
    point();
    point(int);
    point(int, int);
    ~point();
    void display();
};

point ::point()
{
    x = y = 0;
}

point ::point(int a)
{
    x = y = a;
}

point ::point(int a, int b)
{
    x = a;
    y = b;
}

point :: ~point() {
    cout << "The coordinates of the point deleted now are (" << x << "," << y << ")" << endl;
}

void point ::display() {
    cout << "The coordinates of the point are (" << x << "," << y << ")" << endl;
}

int main() {
    point p0;
    point p1(1);
    point p2(2, 3);

    p0.display();
    p1.display();
    p2.display();
}