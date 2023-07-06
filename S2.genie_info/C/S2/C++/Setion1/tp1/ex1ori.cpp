#include <iostream>
using namespace std;

class point
{
    float x;
    float y;
    public : 
    point(float a, float b);
    void deplace(float dx, float dy);
    void display();
};

point :: point(float a, float b){
    x = a;
    y = b;
}

void point :: deplace(float dx, float dy){
    x += dx;
    y += dy;
}

void point :: display(){
    cout << x << " " << y << endl;
}

int main() {
    point p(10,12);
    p.display();
    p.deplace(5,5);
    p.display();
    
    return 0;
}
