#include <iostream>
using namespace std;

class account
{
    static int nAccounts;
    int code;
    float solde;

public:
    float get();
    account(float);
    void toString();
    void depot(float);
    void retrait(float);
};

int account::nAccounts = 0;

float account::get() { return solde; }

account::account(float solde = 0)
{
    code = ++nAccounts;
    this->solde = solde;
}

void account ::depot(float num) { solde += num; }

void account ::retrait(float num)
{
    if (solde >= num)
    {
        solde -= num;
    }
    else
    {
        cout << "Failed Operation!" << endl;
    }
}

void account ::toString() { cout << "Votre Solde est :" << solde <<", Code: " << code<< endl; }

class Epargne : public account
{
    float tauxInteret;

public:
    void set(float);
    void calcIteret();
};

void Epargne::set(float taux) { tauxInteret = taux; }

void Epargne ::calcIteret() { retrait(get() * tauxInteret); }

class payant : public account
{
public:
    void deposer(float num);
    void retirer(float num);
};

void payant ::deposer(float num) { depot(num - 1); }

void payant ::retirer(float num) { retrait(num + 1); }

int main()
{
    account a, b(10000);
    b.depot(50000);
    cout<< "Account B" << endl;
    b.toString();
    b.retrait(10);
    b.toString();
    payant C;
    cout << "Account Payant" << endl;
    C.toString();
    C.deposer(10);
    C.toString();
    Epargne E;
    E.set(0.06);
    E.depot(100);
    E.toString();
    E.calcIteret();
    E.toString();
    return 0;
}
