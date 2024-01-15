#include <iostream>
#include <string>
using namespace std;
string thu[] = {"hai", "ba", "tu", "nam", "sau", "bay", "chu nhat"};
void NhapMang(double a[], long n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "nhiet do thu " << thu[i] << " la: ";
        cin >> a[i];
    }
}
long PhamVi(const double a[], long n, double min, double max)
{
    int soluong = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= min && a[i <= max])
        {
            cout << a[i] << " ";
            soluong++;
        }
    }
    cout << "\n So ngay trong tuan co nhiet do tong pham vi la: ";
    return soluong;
}
double GiaTriTrungBinh(const double a[], long n)
{
    double gttb = 0, tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += a[i];
    }
    gttb = tong / n;
    return gttb;
}
double GiaTriMax(const double a[], long n)
{
    double max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int main()
{
    long luachon;
    double arr[7];
    for (int i = 0; i < 7; i++)
    {
        cout << "Nhap nhiet do thu " << thu[i] << " :";
        cin >> arr[i];
    }
    while (true)
    {

        cout << "\n ==== MENU ====\n"
             << "1-Nhiet do cao nhat\n"
             << "2-Nhiet do trung binh ca tuan\n"
             << "3-Nhiet do trong pham vi [x,y]\n"
             << "4-Nhiet do trung binh n ngay dau tien\n"
             << "5-Ket thuc\n"
             << "Lua chon >";
        cin >> luachon;
        switch (luachon)
        {
        case 5:
        {
            cout << "\nHen gap lai\n";
            return 0;
        }
        case 1:
        {
            cout << "Nhiet do cao nhat trong tuan la: " << GiaTriMax(arr, 7) << endl;
            break;
        }
        case 2:
        {
            cout << "Nhiet do trung binh ca tuan la: " << GiaTriTrungBinh(arr, 7) << endl;
            break;
        }
        case 3:
        {
            double x, y;
            do
            {
                cout << "Nhap pham vi [x,y] voi dieu kien x<=y: ";
                cin >> x >> y;
            } while (x > y);
            cout << "Cac nhiet do trong tuan nam trong pham vi [" << x << "," << y << "] : " << PhamVi(arr, 7, x, y) << endl;
            break;
        }
        case 4:
        {
            long so;
            do
            {
                cout << "Nhap nhiet do trung binh n ngay dau tien \n"
                     << "n = ";
                cin >> so;
            } while (so < 1 && so > 7);
            cout << "Nhiet do trung binh cua " << so << " ngay dau tien la: " << GiaTriTrungBinh(arr, so) << endl;
            break;
        }
        default:
            cout << "Vui long lua chon lai";
            break;
        }
    }
}
