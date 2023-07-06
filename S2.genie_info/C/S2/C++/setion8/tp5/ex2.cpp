#include <iostream>
using namespace std;

class vect
{
protected:
    int elem;
    int *adr;

public:
    vect(int n)
    {
        elem = n;
        adr = new int[n];
    };
    int &operator[](int i) { return adr[i]; };
};

class vectb : public vect
{
protected:
    int start, fin;

public:
    vectb(int d, int f) : vect(f - d + 1)
    {
        start = d;
        fin = f;
    };
};

class vectk : public vect
{
public:
    vectk(int n):vect(n){};
    vectk(vectk &V):vect(V.elem){
        for (int i = 0; i < elem;i++){
            adr[i] = V.adr[i];
        }
    }
    vectk &operator=(const vectk & v){
        delete [] adr;
        elem = v.elem;
        adr = new int[elem];
        for (int i = 0; i < elem;i++){
            adr[i] = v.adr[i];
        }
    };
    int length() { return elem; };
};

int main()
{
    // Create a vect object with 5 elements
    vect v(5);

    // Assign values to the elements of the vect object
    for (int i = 0; i < 5; i++)
    {
        v[i] = i;
    }

    // Print out the values of the vect object
    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // Create a vectb object with start=2 and fin=6
    vectb vb(2, 6);

    // Assign values to the elements of the vectb object
    for (int i = 2; i <= 6; i++)
    {
        vb[i - 2] = i;
    }

    // Print out the values of the vectb object
    for (int i = 2; i <= 6; i++)
    {
        cout << vb[i - 2] << " ";
    }
    cout << endl;

    // Create a vectk object with 3 elements
    vectk vk(3);

    // Assign values to the elements of the vectk object
    for (int i = 0; i < 3; i++)
    {
        vk[i] = i;
    }

    // Print out the values of the vectk object
    for (int i = 0; i < 3; i++)
    {
        cout << vk[i] << " ";
    }
    cout << endl;

    // Create a new vectk object and assign it to the original vectk object
    vectk vk2(5);
    vk2[0] = 10;
    vk2[1] = 20;
    vk = vk2;

    // Print out the values of the original vectk object after assignment
    for (int i = 0; i < 5; i++)
    {
        cout << vk[i] << " ";
    }
    cout << endl;

    // Print out the length of the original vectk object
    cout << "Length of vk: " << vk.length() << endl;

    return 0;
}
