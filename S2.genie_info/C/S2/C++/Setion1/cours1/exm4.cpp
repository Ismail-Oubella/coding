#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
    int nbval;
    int *val;

public:
    Node(int, int);
    ~Node();
    void display();
};

Node :: Node (int nval, int max){
    nbval = nval;
    val = new int [nbval];
    for(int i = 0; i < nbval; i++){
        val[i] = rand() % max;
    }
}

Node :: ~Node (){delete val;}

void Node :: display(){
    for(int i = 0; i < nbval; i++){
        cout << "Val number " << i << " is : "<< val[i] << endl;
    }
}

int main() {
    int n, max;
    
    cout << "Entrer le nombre d'elements in my array : "<< endl;
    cin >> n;

    cout << "Donnez le max de cette array : " << endl;
    cin >> max;

    Node array1(n, max);
    array1.display();

    cout << "Entrer le nombre d'elements in my array : " << endl;
    cin >> n;

    cout << "Donnez le max de cette array : " << endl;
    cin >> max;

    Node array2(n, max);
    array2.display();

    return 0;
}
