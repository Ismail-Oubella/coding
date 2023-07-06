#include <iostream>
using namespace std;

class vehicule
{
    int static nb_voitures;
    int matricule, anne_modaile;
    float prix;

public:
    vehicule(int, float);
    int getMatricule();
    int getModaile();
    void setModaile(int);
    float getPrix();
    void setPrix(float);
    virtual void demarrer() = 0;
    virtual void accelerer() = 0;
    void toString();
};

int vehicule::nb_voitures = 0;

vehicule::vehicule(int anne, float price)
{
    matricule = ++nb_voitures;
    anne_modaile = anne;
    prix = price;
}

int vehicule::getMatricule() { return matricule; }

float vehicule::getPrix() { return prix; }
void vehicule::setPrix(float price) { prix = price; }

int vehicule::getModaile() { return anne_modaile; }
void vehicule::setModaile(int anne) { anne_modaile = anne; }

class voiture : public vehicule
{
public:
    voiture(int, float);
    void demarrer();
    void accelerer();
};

voiture::voiture(int modaile, float price) : vehicule(modaile, price){};

void voiture::demarrer() { cout << "Voiture number " << getMatricule() << " demaree ! \n"
                                << endl; }

void voiture::accelerer() { cout << "Voiture number " << getMatricule() << "  accelere ! \n"
                                 << endl; }

class camion : public vehicule
{
public:
    camion(int, float);
    void demarrer();
    void accelerer();
};

camion::camion(int modaile, float price) : vehicule(modaile, price){};

void camion::demarrer() { cout << "camion number "<< getMatricule() << " demaree ! \n"
                               << endl; }

void camion::accelerer() { cout << "camion number " << getMatricule() << " accelere ! \n"
                                << endl; }

int main()
{

    voiture car(2020, 200000);
    camion truck(2010, 1000000);

    vehicule *tab[2];

    tab[0] = &car;
    tab[1] = &truck;

    for (int i = 0; i < 2; i++)
    {
        tab[i]->demarrer();
        tab[i]->accelerer();
        cout << "#####################################################################\n"
             << endl;
    }

    return 0;
}