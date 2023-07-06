#include <iostream>
using namespace std;
class demo
{
    int x, y;

public:
    demo(int abs = 1, int ord = 0) // constructeur I (0, 1 ou 2 arguments)
    {
        x = abs;
        y = ord;
        cout << "constructeur I: " << x << " " << y << "\n";
    }
    demo(demo &); // constructeur II (par recopie)
    ~demo();      // destructeur
};
demo::demo(demo &d) // ou demo::demo (const demo & d)
{
    cout << "constructeur II (recopie) : " << d.x << " " << d.y << "\n";
    x = d.x;
    y = d.y;
}
demo::~demo()
{
    cout << "destruction: " << x << " " << y << "\n";
}
main()
{
    void fct(demo, demo *); // proto fonction indépendante fct
    cout << "début main\n";
    demo a;
    demo b = 2;
    demo c = a;
    demo *adr = new demo(3, 3);
    fct(a, adr);
    demo d = demo(4, 4);
    c = demo(5, 5);
    cout << "fin main\n";
}
void fct(demo d, demo *add)
{
    cout << "entrée fct\n";
    delete add;
    cout << "sortie fct\n";
}