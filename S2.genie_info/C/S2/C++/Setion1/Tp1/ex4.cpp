#include <iostream>
using namespace std;

class point
{
    static int count;
    float x;
    float y;

public:
    point(float, float);
    ~point();
    void deplace(int);
    void display();
    static void DisNumber();
};

int point::count = 0;

point ::point(float a = 0, float b = 0)
{
    count++;
    x = a;
    y = b;
}

point ::~point(){
    count--;
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

void point ::DisNumber(){
    cout << "Number of objects is " << count << endl;
}

int main() {

    point p;
    p.display();

    point q(2.3, -1);
    q.display();

    int dx;
    cout << "Donnez dx de point : " << endl;
    cin >> dx;

    q.deplace(dx);
    q.display();

    point :: DisNumber();

    return 0;
}


