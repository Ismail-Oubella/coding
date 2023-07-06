#include <iostream>
using namespace std;

int multiply(int a=1, int b=1) {return a*b;}

void display(string str="NONE") {
    cout <<"Hello, " << str<< endl;
}


int main(){
    cout << "The result of multiply(5, 2) is " << multiply(5, 2) << endl;
    cout << "The result of multiply(5) is " << multiply(5) << endl;
    cout << "The result of multiply() is " << multiply() << endl;

    display();
    display("Ismail");

    return 0;
}