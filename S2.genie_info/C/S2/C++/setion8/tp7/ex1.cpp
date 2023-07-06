#include <iostream>
using namespace std;

typedef struct
{
    int dd, MM, yyyy;
} Date;

class employee
{
    int matricule;
    string fullName;
    Date birth;

public:
    employee(int, string, Date);
    employee(){};
    int getMatricule();
    string getName();
    Date getBirth();
    void setMatricule(int);
    void setName(string);
    void setBirth(Date);
    virtual void toString();
    virtual float getSalary() = 0;
};

employee ::employee(int mat, string full, Date bDate)
{
    matricule = mat;
    fullName = full;
    birth = bDate;
}

int employee::getMatricule() { return matricule; }
void employee::setMatricule(int mat) { matricule = mat; }
string employee::getName() { return fullName; }
void employee::setName(string name) { fullName = name; }
Date employee::getBirth() { return birth; }
void employee::setBirth(Date date) { birth = date; }

void employee::toString() { cout << "\nThis Is Employee Informations : \nMatricule: " << matricule << ", Full Name: " << fullName << ", Birth Day: " << birth.dd << "/" << birth.MM << "/" << birth.yyyy << endl; }

class ouvrier : public employee
{
    Date entree;
    static int SMIG;

public:
    void setDate(Date);
    Date getdate();
    float getSalary();
};

Date ouvrier::getdate() { return entree; }
void ouvrier::setDate(Date date) { entree = date; }

int ouvrier::SMIG = 2500;

float enciente(Date birth)
{
    Date now;
    cout << "give dd: " << endl;
    cin >> now.dd;
    cout << "give MM: " << endl;
    cin >> now.MM;
    cout << "give YYYY: " << endl;
    cin >> now.yyyy;
    if (now.yyyy * 356 + now.MM * 30 + now.dd > birth.yyyy * 356 + birth.MM * 30 + birth.dd)
        return ((birth.yyyy - now.yyyy) * 356 + (birth.MM - now.MM) * 30 + (birth.dd - now.dd)) / 365;
    else
        return -1;
}

float ouvrier::getSalary()
{
    if (enciente(entree) != -1)
    {
        float temp = SMIG + enciente(entree) * 100;
        if (temp > SMIG * 2)
            temp = SMIG * 2;
        return temp;
    }
    else
    {
        return -1;
    }
}

class cadre : public employee
{
    int indice;

public:
    void setIndice(int);
    int getIndice();
    float getSalary();
    void toString();
};

void cadre::setIndice(int i) { indice = i; }
int cadre::getIndice() { return indice; }

float cadre::getSalary()
{
    switch (indice)
    {
    case 1:
        return 13000/12;
        break;
    case 2:
        return 15000/12;
        break;
    case 3:
        return 17000/12;
        break;
    case 4:
        return 20000/12;
        break;
    default:
        return -1;
        break;
    }
}

void cadre::toString() { employee::toString();
    cout << "Inidce: " << indice << endl;
}

class patron : public employee
{
    int CA;
    int percentage;

public:
    int getCA();
    int getPer();
    void setCA(int);
    void setPer(int);
    float getSalary();
    void toString();
};

void patron::setCA(int chiffre) { CA = chiffre; }
int patron ::getCA() { return CA; }

void patron::setPer(int per) { percentage = per; }
int patron ::getPer() { return percentage; }

float patron::getSalary() { return CA * percentage / 100; }

void patron:: toString(){
    employee::toString();
    cout << "CA: " << CA << ", Percentage: " << percentage << endl;
}

int main()
{
    // Initialize the ouvrier object
    // Date birthDate = {10, 12, 1995};
    // Date entryDate = {1, 1, 2021};
    // ouvrier ouv;
    // ouv.setMatricule(654321);
    // ouv.setName("Jane Doe");
    // ouv.setBirth(birthDate);
    // ouv.setDate(entryDate);

    // birthDate = {1, 10, 1985};
    // cadre cad;
    // cad.setIndice(3);
    // cad.setMatricule(12322);
    // cad.setName("Paul Pogba");
    // cad.setBirth(birthDate);

    // birthDate = {21, 1, 1999};
    // patron pat;
    // pat.setMatricule(3422);
    // pat.setName("Erling Halaand");
    // pat.setBirth(birthDate);
    // pat.setCA(3);
    // pat.setPer(80);

    // employee* tab [3];
    // tab[0] = &ouv;
    // tab[1] = &cad;
    // tab[2] = &pat;
    // for (int i = 0; i < 3; i++){
    //     tab[i]->toString();
    //     cout << "---------------------------------------------------------------------------";
    //}

    employee *tab[10];

    for (int i = 0; i < 3; i++){
    tab[i] = new ouvrier;
    }

    for (int i = 3; i < 6;i++){
    tab[i] = new cadre;
    }
    for (int i = 6; i < 10;i++)
    {
    tab[i] = new patron;
    }

    for (int i = 0; i < 10;i++){
    cout << "Get salary function: " << tab[i]->getSalary();
    }

    return 0;
}
