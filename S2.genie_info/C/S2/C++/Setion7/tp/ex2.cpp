#include <iostream>
using namespace std;

class assure
{
    float montant;
    string type;

public:
    assure(float, string);
    void affiche();
};

assure ::assure(float mont, string type)
{
    this->montant = mont;
    this->type = type;
}

void assure::affiche() { cout << "Montant : " << montant << ", type: " << type << endl; }

class ordinateur : public assure
{
    int ram, hd;

public:
    ordinateur(float, string, int, int);
    void affiche();
};

ordinateur ::ordinateur(float mont, string type, int ram, int hd) : assure(mont, type)
{
    this->ram = ram;
    this->hd = hd;
}

void ordinateur::affiche()
{
    assure::affiche();
    cout << "ram : " << ram << ", hd: " << hd << endl;
}

class bagage : public assure
{
    string type;
    float poids;

public:
    bagage(float , string , string , float );
    void affiche();
};

bagage ::bagage(float mont, string type, string typee, float poid) : assure(mont, type)
{
    this->type = typee;
    this->poids = poid;
}

void bagage :: affiche(){
    assure::affiche();
    cout << "type : " << type << ", poids: " << poids << endl;
}

int main()
{
    assure a(500, "Assurance auto");
    a.affiche();

    ordinateur o(1000, "Assurance ordinateur", 8, 256);
    o.affiche();

    bagage b(50, "Assurance bagage", "Valise", 20);
    b.affiche();

    return 0;
}
