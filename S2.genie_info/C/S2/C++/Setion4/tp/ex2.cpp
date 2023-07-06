#include <iostream>
#include <cstring>
using namespace std;

class chaine
{
    int length;
    char *name;

public:
    chaine();
    chaine(const char *);
    chaine(chaine &);
    chaine operator=(chaine);
    int operator==(chaine);
    chaine operator+(chaine);
    char operator[](int);
    void display();
};

chaine::chaine()
{
    name = nullptr;
    length = 0;
}

chaine::chaine(const char *ptr)
{
    length = strlen(ptr);
    name = new char[length + 1];
    strcpy(name, ptr);
}

chaine::chaine(chaine &ptr)
{
    length = ptr.length;
    name = new char[length + 1];
    strcpy(name, ptr.name);
}

chaine chaine::operator=(chaine ptr)
{
    if (this != &ptr)
    {
        length = ptr.length;
        delete [] name;
        name = new char[length + 1];
        strcpy(name, ptr.name);
    }
    return *this;
}

int chaine::operator==(chaine ptr)
{
    if (length != ptr.length)
        return 0;
    for (int i = 0; i < length; i++)
    {
        if (name[i] != ptr[i])
            return 0;
    }
    return 1;
}

chaine chaine::operator+(chaine ptr)
{
    chaine temp;
    temp.length = length + ptr.length;
    temp.name = new char[temp.length + 1];
    strcpy(temp.name, name);
    strcat(temp.name, ptr.name);
    return temp;
}

char &chaine::operator[](int i)
{
    static char res = '\0';
    if()
    return name[i];
}

void chaine::display()
{
    cout << "This The String : " << name << endl;
}

int main()
{
    chaine str1("Hello,");
    chaine str2(" World!");
    chaine str3;

    str3 = str1 + str2;

    str3.display();

    if (str1 == str2)
        cout << "str1 is equal to str2" << endl;
    else
        cout << "str1 is not equal to str2" << endl;

    if (str3 == str3)
        cout << "str1 is equal to str3" << endl;
    else
        cout << "str1 is not equal to str3" << endl;

    cout << str3[0] << endl;

    return 0;
}
