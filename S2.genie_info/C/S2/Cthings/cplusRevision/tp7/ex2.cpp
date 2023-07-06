#include <iostream>
using namespace std;

#define SMIG 2500;

struct Date
{
    int dd, MM, yyyy;
};

class employee
{
    int static nb_emp;
    int matricule;
    string first_name, last_name;
    Date birth;

public:
    employee(string, string, Date);
    int getMatricule();
    string getFirstName();
    void setFirstName(string);
    string getLastName();
    void setLastName(string);
    void toString();
    float virtual getSalary() = 0;
};

int employee::nb_emp = 0;

employee::employee(string f_name, string l_name, Date birth_date)
{
    matricule = ++nb_emp;
    first_name = f_name;
    last_name = l_name;
    birth = birth_date;
}

string employee::getFirstName() { return first_name; }
void employee::setFirstName(string f_name) { first_name = f_name; }

string employee::getLastName() { return last_name; }
void employee::setLastName(string l_name) { last_name = l_name; }

void employee::toString()
{
    cout << "Matricule d'employee est: " << matricule << ", Son Nom et Prenom est: " << last_name << " " << first_name << ", Son date de naissance est: " << birth.dd << "/" << birth.MM << "/" << birth.yyyy << ".\n"
         << endl;
}

class ouvrier : public employee
{
    Date join;

public:
    friend int enciente(ouvrier);
    ouvrier(string, string, Date, Date);
    float getSalary();
};

ouvrier::ouvrier(string f_name, string l_name, Date birth_day, Date join_date) : employee(f_name, l_name, birth_day){
    join = join_date;
}

int enciente(ouvrier ouv){
    Date today;
    cout << "We need to provide this information about the date of this day...\n"
         << endl;
    cout << "Day number ...?\t" << endl;
    cin >> today.dd;
    cout << "Month number ...?\t" << endl;
    cin >> today.MM;
    cout << "Year number ...?\t" << endl;
    cin >> today.yyyy;

    int today_days = today.yyyy * 365 + today.MM * 30 + today.dd;
    int join_days = ouv.join.yyyy * 365 + ouv.join.MM * 30 + ouv.join.dd;

    int days = today_days - join_days;
    return days / 365;
}

float ouvrier::getSalary(){
    float salaire = SMIG + (enciente(*this)) * 100;
    if(salaire > 2500 * 2) { return 2500 * 2; }
    return salaire;
}

class cadre: public employee{
    int index;

public:
    cadre(string, string, Date, int);
    float getSalary();
};

cadre::cadre(string f_name, string l_name, Date naissance, int indice) : employee(f_name, l_name, naissance) {
    index = indice;
}

float cadre::getSalary()
{
    switch(index){
    case 1:
        return 130000;
        break;
    case 2:
        return 150000;
        break;
    case 3:
        return 170000;
        break;
    case 4:
        return 200000;
        break;
    default:
        return - 1;
    }
}

class patron : public employee{
    int chiffre_affaires;
    int pourcentage;

public:
    patron(string, string, Date, int, int);
    float getSalary();
};

patron::patron(string f_name, string l_name, Date naissance, int number, int pour) : employee(f_name, l_name, naissance){
    chiffre_affaires = number;
    pourcentage = pour;
}

float patron::getSalary(){
    return chiffre_affaires * pourcentage / 100;
}

