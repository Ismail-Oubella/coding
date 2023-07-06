#include <iostream>
using namespace std;

class point
{
    int x, y;

public:
    point(int, int);
    int getX();
    int getY();
};

point ::point(int x = 0, int y = 0) { this->x = x;this->y = y;}
int point::getX() { return x; }
int point::getY() { return y; }

class pointPolaire : public point{
    float rho;
public:
    
};