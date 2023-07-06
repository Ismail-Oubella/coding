#include <iostream>

using namespace std;

class point
{
    float x, y;
    static int n;

public:
    point(float, float);
    ~point();
    void display();
};

int point ::n = 0;

point ::point(float a = 0, float b = 0)
{
    cout << "You  Have Got " << ++n << " Points " << endl;
    x = a;
    y = b;
}

point ::~point()
{
    cout << "You Still Have Got " << --n << " Points " << endl;
}

void point::display()
{
    cout << "(" << x << "," << y << ") \nYou Have Got " << n << " Points " << endl;
}

int main()
{
    point *tab = new point[4];
    for (int i = 0; i < 4; i++)
    {
        tab[i].display();
    }
    delete[] tab;
    return 0;
}
