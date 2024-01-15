#include <iostream>
#include <math.h>
using namespace std;
double Nhan2So(double a, double b)
{
    double tich;
    tich = a * b;
    return tich;
}
double Tong2So(double a, double b)
{
    double tong;
    tong = a + b;
    return tong;
}
double TongBinhPhuong(double a, double b)
{
    double tongbinhphuong;
    tongbinhphuong = a * a + b * b;
    return tongbinhphuong;
}
double CanBac2(double a)
{
    double canbac2;
    canbac2 = sqrt(a);
    return canbac2;
}
int main()
{
    while (true)
    {
        int luachon;
        cout << "==== MENU ====\n"
             << "1- Thong tin hinh vuong\n"
             << "2- Thong tin hinh chu nhat\n"
             << "3- Thong tin tam giac vuong\n"
             << "4- Cham dut\n"
             << "Lua chon >>";
        cin >> luachon;
        switch (luachon)
        {
        case 4:
        {
            cout << "\nHen gap lai\n";
            return 0;
        }
        case 1:
        {
            double canhhinhvuong;
            do
            {
                cout << "NHap canh hinh vuong >";
                cin >> canhhinhvuong;
                if (canhhinhvuong <= 0)
                    cout << "Vui long nhap lai\n";
            } while (canhhinhvuong <= 0);
            cout << "Chu vi: " << Tong2So(Tong2So(canhhinhvuong, canhhinhvuong), Tong2So(canhhinhvuong, canhhinhvuong)) << endl;
            cout << "Dien tich: " << Nhan2So(canhhinhvuong, canhhinhvuong) << endl;
            cout << "Chieu dai duong cheo la: " << CanBac2(TongBinhPhuong(canhhinhvuong, canhhinhvuong)) << endl;
            break;
        }

        case 2:
        {
            double dodai1, dodai2;
            do
            {
                cout << "NHap do dai hai canh hinh chu nhat >";
                cin >> dodai1 >> dodai2;
                if (dodai1 <= 0 && dodai2 <= 0)
                    cout << "Vui long nhap lai\n";
            } while (dodai1 <= 0 && dodai2 <= 0);
            cout << "Chu vi: " << Tong2So(Tong2So(dodai1, dodai2), Tong2So(dodai1, dodai2)) << endl;
            cout << "Dien tich: " << Nhan2So(dodai1, dodai2) << endl;
            cout << "Chieu dai duong cheo la: " << CanBac2(TongBinhPhuong(dodai1, dodai2)) << endl;
            break;
        }
        case 3:
        {
            double canh1, canh2;
            do
            {
                cout << "Nhap hai canh goc vuong: ";
                cin >> canh1 >> canh2;
                if (canh1 <= 0 && canh2 <= 0)
                    cout << "Vui long nhap lai\n";
            } while (canh1 <= 0 && canh2 <= 0);

            cout << "Chu vi: " << Tong2So(Tong2So(canh1, canh2), CanBac2(TongBinhPhuong(canh1, canh2))) << endl;
            cout << "Dien tich: " << Nhan2So(canh1, canh2) / 2 << endl;
            cout << "Chieu dai duong cheo la: " << CanBac2(TongBinhPhuong(canh1, canh2)) << endl;
            break;
        }
        default:
        {
            cout << "Vui long nhap lai \n";
            break;
        }
        }
    }
}