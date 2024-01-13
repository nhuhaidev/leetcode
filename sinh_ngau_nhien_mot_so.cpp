#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;
bool songuyento(int num)
{
    bool tmp = true;
    if (num == 2)
        return tmp;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            tmp = false;
    }
    return tmp;
}
int main()
{
    srand(time(NULL));
    int num_rand;
    num_rand = rand() % 100 + 1;

    cout << "Doan so ngau nhien = ";
    while (true)
    {

        int num_in;
        cin >> num_in;
        if (num_in != num_rand)
        {
            if (num_in > num_rand)
            {
                system("clear");
                cout << "Be hon\n"
                     << "> ";
            }

            else if (num_in < num_rand)
            {
                system("clear");
                cout << "Lon hon\n"
                     << "> ";
            }
        }
        else
        {
            cout << " Ban da doan dung\n";
            break;
        }
    }
    if (num_rand >= 2)
    {
        cout << "So ngau nhien vua sinh ra " << num_rand << " " << (songuyento(num_rand) ? "la" : "khong la") << " so nguyen to\n";
    }
    return 0;
}
