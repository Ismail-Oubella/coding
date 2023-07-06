#include <iostream>
#include <cmath>
using namespace std;

class point
{
    float x, y;

public:
    point(float, float);
    void deplace(float, float);
    float abscisse();
    float ordonnee();
    void homothetie(float);
    void rotation(float);
    float rho();
    float theta();
    void display();
};

float angle(float x, float y){
    float ang = atan(fabs(y / x));
    if ( x > 0 && y > 0 ) return ang;
    if(x > 0 && y < 0) return -ang;
    if(x < 0 && y > 0) return M_PI -ang;
    return M_PI +ang; 
}

point ::point(float a = 0, float b = 0)
{
    x = a;
    y = b;
}

void point ::deplace(float a, float b)
{
    x += a;
    y += b;
}

float point ::abscisse(){return x;}

float point ::ordonnee(){return y;}

void point ::homothetie(float a) {
    x*=a;
    y*=a;
}

float point ::rho() {return sqrt(x*x + y*y);}

float point ::theta() {return angle(x, y);}

void point ::rotation(float theeta) {
    float ang = theta();
    ang = ang + theeta;
    float r =rho();

    x= r*cos(ang);
    y= r*sin(ang);
}

void point ::display()
{
    cout << "Les coordonnes de votre point est : (" << x << "," << y << ")" << endl;
}

int main() {
    int x, y;
    
    cout << "Donnez x : " << endl;
    cin >> x;

    cout << "Donnez y : " << endl;
    cin >> y;
    point p(x, y);
    p.display();

    cout << "Donnez dx : " << endl;
    cin >> x;

    cout << "Donnez dy : " << endl;
    cin >> y;
    p.deplace(x, y);
    p.display();

    cout << "Donnez x d'homothetie : " << endl;
    cin >> x;
    p.homothetie(x);
    p.display();

    cout << "Donnez une angle de rotation : " << endl;
    cin >> y;
    p.rotation(y);
    p.display();

    return 0;    
}
