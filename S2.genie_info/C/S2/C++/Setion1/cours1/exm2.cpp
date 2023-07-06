#include <iostream>
using namespace std;

class point
{
    int x;
    int y;

public:
    void initialis(int, int);
    void deplace(int);
    void display();
};

void point::initialis(int a, int b){
    x = a;
    y = b;
}

void point::deplace(int dxy){
    x+=dxy;
    y+=dxy;
}

void point ::display()
{
    cout << "The coordinates of the point are (" << x << "," << y << ")" << endl;
}

int main()
{
    int a, b;
    point p;
    cout << "We have just created a point so we need to enter its coordinates" << endl;

    cout << "Give x= " << endl;
    cin >> a;

    cout << "Give y= " << endl;
    cin >> b;

    cout << "We have got the coordinates of the point" << endl;

    p.initialis(a, b);
    p.display();
    int dp;

    cout << "We want to deplace this point by dx give to us a value : " << endl;
    cin >> dp;

    p.deplace(dp);
    p.display();
    
    return 0;
}