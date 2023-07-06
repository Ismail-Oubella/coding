#include <iostream>
using namespace std;

class objet_assure
{
    float montant;
    string type;

public:
    objet_assure(){};
    objet_assure(float, string);
    void toString();
};

objet_assure::objet_assure(float price, string type)
{
    montant = price;
    this->type = type;
}

void objet_assure::toString()
{
    cout << "Montant de cette objet est: " << montant << ", and it's type is: " << type << ".\n"
         << endl;
}

class ordinateur : public virtual objet_assure
{
    int ram, hd;

public:
    ordinateur(float, string, int, int);
    void toString();
};

ordinateur::ordinateur(float price, string type, int ram, int hd) : objet_assure(price, type)
{
    this->ram = ram;
    this->hd = hd;
}

void ordinateur::toString() { cout << "Ram: " << ram << ", and hd: " << hd << ".\n"
                                   << endl; }

class bagage : public virtual objet_assure
{
    float poids;
    string type;

public:
    bagage(float, string, float, string);
    void toString();
};

bagage::bagage(float price, string type, float poid, string type_b) : objet_assure(price, type)
{
    poids = poid;
    type = type_b;
}

void bagage::toString()
{
    cout << "The poids of this type: " << type << " , is " << poids << "\n"
         << endl;
}

class ordinateur_portable : public ordinateur, public bagage
{
    float poids;
    float epaisseur;

public:
    ordinateur_portable(float, string, int, int, float, string, float, float);
    void toString();
};

ordinateur_portable::ordinateur_portable(float price, string type, int ram, int hd, float poid, string type_b, float poids, float epaisseur) : ordinateur(price, type, ram, hd), bagage(price, type, poid, type_b), objet_assure(price, type)
{
    this->poids = poids;
    this->epaisseur = epaisseur;
}

void ordinateur_portable::toString()
{
    objet_assure::toString();
    ordinateur::toString();
    bagage::toString();
    cout << "Poids de l'ordinateur est: " << poids << ", et l'epaisseur est: " << epaisseur << "\n"
         << endl;
}

int main()
{
    objet_assure objet(15000, "Lenovo");
    ordinateur nouveau(1, "hp", 12, 256);

    cout << "showing objet_assure dispaly class : \n"
         << endl;
    objet.toString();

    cout << "#####################################################################\n"
         << endl;

    cout << "showing ordinateur dispaly class : \n"
         << endl;
    nouveau.toString();

    cout << "#####################################################################\n"
         << endl;

    ordinateur_portable portable(20000, "Apple", 16, 1024, 8, "i don't know", 8, 1);

    cout << "showing ordinateur_portable dispaly class : \n"
         << endl;
    portable.toString();

    cout << "#####################################################################\n"
         << endl;

    return 0;
}