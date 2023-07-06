#include <iostream>
using namespace std;

class Batiment
{
    string adress;

public:
    Batiment();
    Batiment(string);
    string get();
    void set(string);
    void toString();
};

Batiment ::Batiment() { adress = ""; }
Batiment ::Batiment(string adress) { this->adress = adress; }
string Batiment::get() { return adress; }
void Batiment ::set(string adress) { this->adress = adress; }
void Batiment ::toString() { cout << "Adress De Batiment est : " << adress << endl; }

class Maison : public Batiment
{
    int NbPieces;

public:
    Maison();
    Maison(string, int);
    int get();
    void set(int);
    void toString();
};

Maison ::Maison() { NbPieces = 0; }
Maison ::Maison(string Adress, int NbPieces) : Batiment(Adress) { this->NbPieces = NbPieces; }
int Maison ::get() { return NbPieces; }
void Maison ::set(int num) { NbPieces = num; }
void Maison ::toString() { cout << "Adress De Batiment est : " << Batiment::get() << ", Nombre des Pieces est : " << NbPieces << endl; }

int main()
{
    Batiment b("123 Rue de la Paix");

    b.toString();
    b.set("456 Rue du Commerce");
    b.toString();

    Maison m("789 Avenue des Champs-Elysees", 5);

    m.toString();
    m.set(6);
    m.toString();

    return 0;
}