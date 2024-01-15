#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int maxchan = 0, minarr = INT16_MAX;
void TaoMang(int a[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        a[i] = 20 + rand() % 61;
    }
}
void InMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void Timmaxmin(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            if (a[i] >= maxchan)
                maxchan = a[i];
        }
        if (a[i] < minarr)
            minarr = a[i];
    }
}
void XapXep(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int tmp;
            if (a[i] > a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
void TimChaneLe(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 1)
            cout << a[i] << " ";
    }
    cout << "\t";
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            cout << a[i] << " ";
    }
}
int main()
{
    int arr[100], size;
    cout << "Nhap n: ";
    cin >> size;
    TaoMang(arr, size);
    InMang(arr, size);
    Timmaxmin(arr, size);
    cout << "\nMax chan: " << maxchan << endl
         << "Min: " << minarr << endl;
    XapXep(arr, size);
    TimChaneLe(arr, size);
    return 0;
}