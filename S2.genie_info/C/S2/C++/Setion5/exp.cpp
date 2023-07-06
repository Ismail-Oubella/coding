#include <iostream>
using namespace std;

class vecteur
{
    float x, y;

public:
    void initialise(float = 0, float = 0);
    void homothetie(float);
    void affichage();
};

void vecteur::initialise(float abs, float ord){
    x = abs;
    y = ord;
}

void vecteur::homothetie(float abs)
{
    x *= abs;
    y *= abs;
}

void vecteur:: affichage(){
    cout 
}
