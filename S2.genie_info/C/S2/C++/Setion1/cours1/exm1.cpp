#include <iostream>
using namespace std;

void function(int &a) { a++; }

int main()
{
    cout << "Hello, World!" << endl;
    string name;
    cout << "What is your name? " << endl;
    cin >> name;
    int length = name.length();
    cout << "My name is " << name << ", it's length is " << length << endl;
    int s;
    cout << "Give a value to our var 's' (int ): " << endl;
    cin >> s;
    cout << "Number is " << s << endl;

    float *array = new float[length];
    cout << "Give " << length << " float numbers to this array :" << endl;
    
    for(int i = 0; i < length; i++){
        cout << "Element number " << i << " : " << endl;
        cin >> array[i];
    }

    cout <<"This is your array :" <<endl;
    
    for(int i = 0; i < length; i++){
        cout << "Element number " << i<< " is : "<< array[i] << endl;
    }

    delete array;

    int i;
    int &j(i);

    i = 10;
    cout << "i = " << i << " and j = " << j << endl;

    j = 4;
    cout << "i = " << i << " and j = " << j << endl;

    function(i);
    cout <<"Result of function : "<< endl;
    cout << "i = " << i << " and j = " << j << endl;

    return 0;
}