#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;
const double PI = 3.1416;
int main()
{
    int a, b, c;
    bool dieu_kien = false;
    int max, min;
    char luacchon;
    do
    {

        cout << "=======MENU======\n"
             << "b.Tinh tong: S = 1 + 2 + ....+ n (n>0+)\n"
             << "c.Tinh dien tich hinh tron voi ban kinh r, lam trong den ba chu so phap phan, voi Pi = 3,1416\n"
             << "d.Kiem tra 1 so nguyen co phai la so nguyen to khong\n"
             << "e.Nhap vao 3 so nguyen, tim so lon nhat, so nho nhat\n"
             << "f.Tiep theo cau e, sap sep cac so thu tu tang dan, giam dan\n"
             << "x.De thoat\n"
             << "Lua chon > ";
        cin >> luacchon;
        switch (luacchon)
        {
        case 'b':
        {
            system("clear");
            int n;
            cout << "b.Tinh tong: S = 1 + 2 + ....+ n (n>0)\n";
            do
            {
                cout << "Nhap n = ";
                cin >> n;
                if (n <= 0)
                    cout << "Vui long nhap lai n >0 \n";
            } while (n <= 0);

            cout << "Tong s = " << n * (1 + n) / 2 << endl;
            break;
        }
        break;

        case 'c':
        {
            system("clear");
            double r, S;
            cout << "c.Tinh dien tich hinh tron voi ban kinh r (r > 0), lam trong den ba chu so phap phan, voi Pi = 3,1416\n";
            do
            {
                cout << "Nhap r = ";
                cin >> r;
                if (r <= 0)
                    cout << "vui long nhap lai r > 0\n";
            } while (r <= 0);

            S = PI * r * r;
            cout << "Dien tich hinh tron s = " << setprecision(3)
                 << fixed << S << endl;
            break;
        }
        case 'd':
        {
            system("clear");
            int n;
            cout << "d.Kiem tra 1 so nguyen co phai la so nguyen to khong voi n >=2 \n";

            do
            {
                cout << "Nhap n = ";
                cin >> n;

                if (n < 2)
                    cout << "Vui long nhap lai n\n";
            } while (n < 2);
            bool so_nguyen_to = true;

            for (int i = 2; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                    so_nguyen_to = false;
            }

            cout << n << (so_nguyen_to ? " la " : " khong la ") << "so nguyen to" << endl;
            break;
        }
        case 'e':
        {

            system("clear");
            cout << "e.Nhap vao 3 so nguyen, tim so lon xnhat, so nho nhat\n";
            cout << "Nhap lan luot 3 so nguyen to: ";
            cin >> a >> b >> c;
            max = a;
            min = a;
            if (b > max)
                max = b;
            if (c > max)
                max = c;
            if (b < min)
                min = b;
            if (c < min)
                min = c;

            cout << "So lon nhat la" << max << endl
                 << "so be nhat la " << min << endl;
            dieu_kien = true;

            break;
        }
        case 'f':
        {
            cout << "f.Tiep theo cau e, sap sep cac so thu tu tang dan, giam dan\n";
            while (dieu_kien)
            {
                cout << "sap sep tu be den lon: " << min << " " << (a + b + c) - (max + min) << " " << max << endl;
                cout << "sap sep tu lon den be: " << max << " " << (a + b + c) - (max + min) << " " << min << endl;
                break;
            }
            if (dieu_kien == false)
                cout << "Vui long lam cau e truoc\n";

            break;
        }
        case 'x':
        {
            return 0;
        }
        }

        if (luacchon != 'b' && luacchon != 'c' && luacchon != 'd' && luacchon != 'e' && luacchon != 'f')
            cout << "Xin vui long lua chon lai\n";
    } while (luacchon != 'b' || luacchon != 'c' || luacchon != 'd' || luacchon != 'e' || luacchon != 'f');
}