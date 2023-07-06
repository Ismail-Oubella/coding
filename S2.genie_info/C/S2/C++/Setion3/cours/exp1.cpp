#include <iostream>
using namespace std;

class point
{
    float x, y;

public:
    friend point operator+(point, point);
    point(float, float);
    void display();
};

point :: point (float a = 0, float b =0){x = a;y = b;}

point operator+(point A, point B){
    point temp;
    temp.x = A.x + B.x;
    temp.y = A.y + B.y;
    return temp;
}

void point :: display(){
    cout << "Coord Of Your Point : (" << x << "," << y << ") " << endl;
}

int main(){
    point A(4, 3);
    point B(10, 0);
    A.display();
    B.display();
    (A+B).display();

    return 0;
}