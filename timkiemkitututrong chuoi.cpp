#include <iostream>
#include <string.h>
using namespace std;
char arr[] = {"a2def"};
int sizearr = strlen(arr);
int slktchu = 0,
    slktso = 0;
void ktnum(char num)
{

    if (num >= '0' && num <= '9')
        slktso++;
}
void ktword(char word)
{

    if (word >= 'a' && word <= 'z' || word >= 'A' && word <= 'Z')
    {
        slktchu++;
    }
}

int main()
{

    for (int i = 0; i < sizearr; i++)
    {

        ktword(arr[i]);
        ktnum(arr[i]);
    }
    cout << slktchu << endl
         << slktso;
}
