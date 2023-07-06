#include <iostream>
using namespace std;

class forms
{
public:
    virtual void affiche()
    {
        cout << "Ceci Est Une forme!" << endl;
    };
    virtual float air() = 0;
};

class cercle : public forms
{
    float rayon;

public:
    cercle(float r = 0) { rayon = r; }
    void affiche()
    {
        cout << "Ceci Est Un Cercle" << endl;
    }
    float air();
};

class triangle : public forms
{
    float hauteur, base;

public:
    triangle(float h = 0, float b = 0)
    {
        hauteur = h;
        base = b;
    }
    float air();
    void affichage();
};

class carre : public forms
{
    float cote;

public:
    carre(float c=0) { cote = c; }
    float air();
    void affichage();
};

void
discription(forms &U)
{
    U.affiche();
}

int main()
{
    // forms one, two;
    cercle three;

    // discription(one);
    discription(three);

    return 0;
}
