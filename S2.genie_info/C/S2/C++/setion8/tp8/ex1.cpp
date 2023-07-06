#include <iostream>
using namespace std;

struct Date
{
    int dd, MM, yyyy;
};

class article
{
protected:
    int code;
    string designation;
    double prix;
    string categorie;

public:
    article(){};
    article(int, string, double, string);
    virtual float getPrice();
    void setPrice(float price);
    void toString();
    int equal(article);
};

article::article(int code, string dis, double price, string cat)
{
    this->code = code;
    designation = dis;
    prix = price;
    if (cat == "Informatique" || cat == "Bureautique")
    {
        categorie = cat;
    }
    else
    {
        cout << "Operation failed to insert value in categorie" << endl;
    }
}
void article ::setPrice(float price) { prix = price; }
float article::getPrice() { return prix; }
void article::toString()
{
    cout << "Code article: " << code << ", designation: " << designation << ", prix: " << prix << "et Categorie: " << categorie << endl;
}

int article::equal(article ar)
{
    return (this->code == ar.code && this->designation == ar.designation && prix == ar.prix && categorie == ar.categorie);
}

class articleEnSold : public article
{
    int remise;

public:
    articleEnSold(){};
    articleEnSold(int, string, double, string, int);
    float getPrice();
};

articleEnSold::articleEnSold(int code, string desc, double prix, string cat, int pour) : article(code, desc, prix, cat) { remise = pour; }

float articleEnSold::getPrice() { return prix - prix * (remise / 100); }

class facture
{
    Date factur;
    static int numero;
    achat *list;
    int nElements;

public:
    facture(Date date, achat *liste, int nombre)
    {
        factur = date;
        nElements = nombre;
        numero++;
        liste = new achat[nombre];
        for (int i = 0; i < nombre;i++){
            *(list + i) = *(liste + i);
        }
    }
    facture(facture &f){
        factur = f.factur;
        nElements = f.nElements;
        list = new achat[nElements];
        for (int i = 0; i < nElements;i++){
            *(list + i) = *(f.list + i);
        }
    }
};

int facture::numero = 0;

class achat
{
    int numero_achat;
    articleEnSold article_achete;
    int quantity;

public:
    achat(int numero, articleEnSold article, int quantite)
    {
        numero_achat = numero;
        article_achete = article;
        quantity = quantite;
    }
    achat() {}
};

struct Date
{
    int dd, MM, yyyy;
};

// class facture
// {
//     Date factur;
//     static int numero;
//     achat *list;
//     int nElements;

// public:
//     facture(Date, achat *, int);
// };

// int facture::numero = 0;

// facture:: facture(Date date, achat *liste, int nombre)
// {
//     numero++;
//     facture = date;
//     nElements = nombre;
//     liste = new achat [nElements];
//     for (int i = 0; i < nElelment;i++){
//         *(list + i) = *(liste + i);
//     }
// }

// class achat
// {
//     int numero_achat;
//     articleEnSold article_achete;
//     int quantity;

// public:
//     achat(int, articleEnSold, int);
//     achat(){};
// };

// achat :: achat(int num, articleEnSold article, int qu ){
//     numero_achat = num;
//     article_achete = article;
//     quantity = qu;
// }
