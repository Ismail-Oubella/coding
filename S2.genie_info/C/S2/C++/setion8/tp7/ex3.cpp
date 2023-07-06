#include <iostream>
using namespace std;

typedef struct
{
    int dd, MM, yyyy;
} Date;

class personne
{
    string name, fName;
    Date birth;

public:
    personne(string, string, Date);
    virtual void display() = 0;
};

personne ::personne(string name, string fname, Date date)
{
    this->name = name;
    fName = fname;
    birth = date;
}

void personne::display()
{
    cout << "Personne Class" << endl;
    cout << "This is " << name << " " << fName << "and his birth day is " << birth.dd << "/" << birth.MM << "/" << birth.yyyy << endl;
}

class employee : public personne
{
    float sal;

public:
    employee(string, string, Date, float);
    float getSal();
    void setSal(float);
    void display();
};

float employee::getSal() { return sal; }
void employee::setSal(float sal) { this->sal = sal; }
void employee::display()
{
    personne::display();
    cout << "Salary of this employee is " << sal << endl;
}

employee ::employee(string name, string last, Date date, float sal) : personne(name, last, date)
{
    this->sal = sal;
}

class chief : public employee
{
    string Service;

public:
    string getService();
    void setService(string);
    chief(string, string, Date, float, string);
    void display();
};

chief ::chief(string name, string last, Date date, float sal, string ser) : employee(name, last, date, sal)
{
    Service = ser;
}

void chief ::display()
{
    employee::display();
    cout << "Service de Chief: " << Service << endl;
}

string chief::getService() { return Service; }
void chief ::setService(string ser) { Service = ser; }

class direc : public chief
{
    string society;

public:
    direc(string, string, Date, float, string, string);
    void setSociety(string);
    string getSociety();
    void display();
};

direc::direc(string name, string last, Date date, float sal, string ser, string soc) : chief(name, last, date, sal, ser)
{
    this->society = soc;
}

void direc::setSociety(string soc) { this->society = soc; }
string direc::getSociety() { return society; }

void direc ::display()
{
    chief::display();
    cout << "Society de Directeur est: " << society << endl;
}

int main()
{

    personne *tab[10];
    tab[0] = new employee("Ismail", "Oubella", {10, 5, 2000}, 100000);
    tab[1] = new employee("lkfdjs", "lkdsfj", {10, 2, 2020}, 104400);
    tab[2] = new employee("gs", "lskjdq", {1, 9, 1999}, 19400);
    tab[3] = new employee("kjkj", "mlK", {7, 8, 2000}, 100000);

    tab[4] = new chief("lkfdjs", "lkdsfj", {10, 2, 2020}, 104400, "There is no Service for now");
    tab[5] = new chief("gs", "lskjdq", {1, 9, 1999}, 19400, "There is no Service for now");
    tab[6] = new chief("kjkj", "mlK", {7, 8, 2000}, 100000, "There is no Service for now");

    tab[7] = new direc("lkfdjs", "lkdsfj", {10, 2, 2020}, 104400, "There is no Service for now", "Ghzoua City");
    tab[8] = new direc("gs", "lskjdq", {1, 9, 1999}, 19400, "There is no Service for now", "Ghzoua City");
    tab[9] = new direc("kjkj", "mlK", {7, 8, 2000}, 100000, "There is no Service for now", "Ghzoua City");

    for (int i = 0; i < 10; i++)
    {
        tab[i]->display();
        cout << "####################################################\n"
             << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        delete tab[i];
    }
    return 0;
}