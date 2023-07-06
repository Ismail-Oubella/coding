#include <iostream>
using namespace std;

class batiments
{
    string adress;

public:
    batiments(){};
    batiments(string);
    string getAdress();
    void setAdress(string);
    void toString();
};

batiments::batiments(string Adress) { adress = Adress; }

string batiments::getAdress() { return adress; }

void batiments::setAdress(string Adress) { adress = Adress; };

void batiments::toString() { cout << "Adress de batiment est: " << adress << "\n"
                                  << endl; }

class maison : public batiments
{
    int nbPieces;

public:
    maison(){};
    maison(string, int);
    int getNbp();
    void setNbp(int);
    void toString();
};

maison::maison(string adress, int number) : batiments(adress) { nbPieces = number; }

int maison::getNbp() { return nbPieces; }

void maison::setNbp(int number) { nbPieces = number; }

void maison::toString() {
    batiments::toString();
    cout << "Nombre de pieces est: " << nbPieces  << "\n" << endl;
}

int main(){

    maison house("Mine", 10);
    house.toString();

    house.setAdress("Yours");
    house.setNbp(5);

    house.toString();

    return 0;
}