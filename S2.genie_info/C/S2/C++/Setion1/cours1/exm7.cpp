#include <iostream>
using namespace std;

class point
{
    int x;
    int y;

public:
    point(int, int);
    void comp(point);
    void comp(point *);
};

point ::point(int a = 0, int b = 0)
{
    x = a;
    y = b;
}

void point :: comp(point p) {
    if (p.x == x && p.y == y)
    {
        cout << "Point is in the same position" << endl;
    }
    else
    {
        cout << "Point is not in the same position" << endl;
    }
}

void point :: comp(point *p) {
    if (p->x == x && p->y == y)
    {
        cout << "Point is in the same position" << endl;
    }
    else
    {
        cout << "Point is not in the same position" << endl;
    }
}

int main (){
    point p(1);
    point q(1,0);
    
    cout <<"Passage par Valeur :" << endl;
    p.comp(q);

    point r(1,1);

    cout << "Passage par Adress :" << endl;
    p.comp(&r);

    return 0;
}
