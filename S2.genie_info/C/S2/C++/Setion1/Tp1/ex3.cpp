#include <iostream>
#include <cmath>
using namespace std;

class point
{
    float prho, ptheta;

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

float angle(float x, float y)
{
    float ang = atan(fabs(y / x));
    if (x > 0 && y > 0)
        return ang;
    if (x > 0 && y < 0)
        return -ang;
    if (x < 0 && y > 0)
        return M_PI - ang;
    return M_PI + ang;
}

point ::point(float a = 0, float b = 0)
{
    ptheta = b;
    prho = a;
}

float point ::abscisse(){return prho*cos(ptheta);}

float point ::ordonnee() { return prho * sin(ptheta); }

void point :: deplace(float a, float b){
    float x = abscisse();
    float y= ordonnee();

    x += a;
    y+= b;

    prho = sqrt(x*x + y*y);
    ptheta = angle(x, y);
}

void point ::homothetie(float a)
{
    float x = abscisse();
    float y = ordonnee();

    x *= a;
    y *= a;

    prho = sqrt(x * x + y * y);
    ptheta = angle(x, y);
}

void point ::rotation(float ang) { ptheta += ang;}

void point ::display()
{
    cout << "Les coordonnes de votre point est : (r= " << prho << " ,Θ= " << ptheta << ")" << endl;
}

int main() {
    int r, thet;

    cout << "Donnez r : " << endl;
    cin >> r;

    cout << "Donnez thet : " << endl;
    cin >> thet;
    point p(r, thet);
    p.display();

    float x, y;

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
