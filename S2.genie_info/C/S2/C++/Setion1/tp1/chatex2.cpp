#include <iostream>
#include <cmath>

class Point
{
public:
    // Constructeur par défaut
    Point() : x(0), y(0) {}

    // Constructeur avec arguments
    Point(double x, double y) : x(x), y(y) {}

    // Fonction membre deplace
    void deplace(double dx, double dy)
    {
        x += dx;
        y += dy;
    }

    // Fonction membre abscisse
    double abscisse() const
    {
        return x;
    }

    // Fonction membre ordonnee
    double ordonnee() const
    {
        return y;
    }

    // Fonction membre homothetie
    void homothetie(double rapport)
    {
        x *= rapport;
        y *= rapport;
    }

    // Fonction membre rotation
    void rotation(double angle)
    {
        double nouveau_x = x * cos(angle) - y * sin(angle);
        double nouveau_y = x * sin(angle) + y * cos(angle);
        x = nouveau_x;
        y = nouveau_y;
    }

    // Fonction membre rho
    double rho() const
    {
        return sqrt(x * x + y * y);
    }

    // Fonction membre theta
    double theta() const
    {
        return atan2(y, x);
    }

private:
    double x;
    double y;
};

int main()
{
    Point p1(1, 2);
    Point p2 = p1;
    p2.deplace(3, 4);
    std::cout << "p1 = (" << p1.abscisse() << ", " << p1.ordonnee() << ")" << std::endl;
    std::cout << "p2 = (" << p2.abscisse() << ", " << p2.ordonnee() << ")" << std::endl;
    p1.homothetie(2);
    std::cout << "p1 après homothétie = (" << p1.abscisse() << ", " << p1.ordonnee() << ")" << std::endl;
    p2.rotation(M_PI / 2);
    std::cout << "p2 après rotation = (" << p2.abscisse() << ", " << p2.ordonnee() << ")" << std::endl;
    std::cout << "rho de p1 = " << p1.rho() << std::endl;
    std::cout << "theta de p1 = " << p1.theta() << std::endl;
    return 0;
}