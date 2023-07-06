#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int anne_achat;
    double prix_achat, prix_courant;

public:
    void affiche();
    void calculePrix();
    Vehicle(int, double);
};

Vehicle::Vehicle(int anne, double achat)
{
    anne_achat = anne;
    prix_achat = achat;
}

void Vehicle::calculePrix()
{
    prix_courant = (1 - ((2015 - anne_achat) * .01) * prix_achat);
}

void Vehicle::affiche()
{
    cout << "Anne_Achat = " << anne_achat << ", Prit_Achat = " << prix_achat << ", Prit_Courant = " << prix_courant << endl;
}

class Camion : public Vehicle
{
protected:
    int Volume;

public:
    void affiche();
    void calculePrixC();
    Camion(int, double, int);
};

void Camion::calculePrixC()
{
    prix_courant = (1 - 0.1 * Volume / 100) * prix_achat;
}

Camion::Camion(int anne, double prix, int Vol) : Vehicle(anne, prix)
{
    Volume = Vol;
}

void Camion::affiche()
{
    cout << "Anne_Achat = " << anne_achat << ", Prit_Achat = " << prix_achat << ", Prit_Courant = " << prix_courant << ", Volume = " << Volume << endl;
}

class Voiture : public Vehicle
{
protected:
    int nombre_portes;
    double puissance, kilometrage;

public:
    void affiche();
    void calculPrix();
    Voiture(int, double, int, double, double);
};

Voiture ::Voiture(int anne, double courant, int nportes, double puiss, double km) : Vehicle(anne, courant)
{
    nombre_portes = nportes;
    puissance = puiss;
    kilometrage = km;
}

void Voiture::calculPrix()
{
    prix_courant = (1 - ((2015 - anne_achat) * .02 + .05 * kilometrage / 10000)) * prix_achat;
}

void Voiture::affiche()
{
    cout << "nombre_portes = " << nombre_portes << ", Puissance = " << puissance << ", kilometragr = " << kilometrage << endl;
}

int main()
{
    cout << "Objet De Type Vehicule \n"
         << endl;
    Vehicle principal(2011, 30000);
    principal.calculePrix();
    principal.affiche();

    cout << "Objet De Type Camion \n"
         << endl;
    Camion camion(2002, 2500000, 100);
    camion.calculePrixC();
    camion.affiche();
    cout << "Objet De Type Voiture \n"
         << endl;
    Voiture voiture(1982, 7327.30, 3, 65, 3000);
    voiture.calculPrix();
    voiture.affiche();
    return 0;
}