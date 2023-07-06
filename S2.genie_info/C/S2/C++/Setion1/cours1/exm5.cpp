#include <iostream>
using namespace std;

class obj
{
    static int count;

public:
    obj();
    ~obj();
    static void counter();
};

int obj :: count = 0;

obj :: obj (){
    cout << "Construction : il y a maintenant " << ++count <<" objets "<< endl;
}

obj :: ~obj (){
    cout << "Destruction : il reste maintenant " << --count << " objets"<< endl;
}

void obj :: counter() {
    cout <<"Vous avez maintenent " << count << " objets"<< endl;
}

int main() {
    obj a;
    obj b;
    obj c;
    obj d;
    obj :: counter();
    return 0;
}