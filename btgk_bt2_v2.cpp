#include <iostream>
#include <string>
#include <limits.h>
using namespace std;
const int MAX_ARR = 100;
int arr[MAX_ARR];
const string PROMPT = "\n=====MENU====\n"
                      "a.Nhap mang arr voi n phan tu (n > 0)\n"
                      "b.In ra manh hinh mang vua nhap\n"
                      "c.Dem cac phan tu chan pha tu le\n"
                      "d.Tim so am lon nhat, so duong be nhat\n"
                      "e.Xoa phan tu tai vij tri bat ki (nguoi dung chon)\n"
                      "f.Nhap vao n. Gan gia tri cac phan tu theo chuoi Fibonacci\n"
                      "x.De thoat\n";
int main()
{
    char lua_chon;
    int n, max_am, min_duong;
    int gt_chan, gt_le = 0;
    bool dieu_kien = false;

    while (true)
    {
        cout << PROMPT;
        cin >> lua_chon;

        system("clear");
        if (lua_chon == 'x')
            return 0;

        if (lua_chon == 'a')
        {
            cout << "vui long nhap so phan tu (n > 0) n = ";
            while (!dieu_kien)
            {
                cin >> n;
                if (n <= 0)
                {
                    cout << "Vui long nhap lai n >0\n";
                    continue;
                }

                for (int i = 0; i < n; i++)
                {
                    cout << "Phan tu thu " << i + 1 << " >";
                    cin >> arr[i];
                }
                dieu_kien = true;
            }
            continue;
        }

        if (lua_chon == 'f')
        {
            int num;
            int arr_fibo[MAX_ARR];
            arr_fibo[0] = 1;
            arr_fibo[1] = 1;
            cout << "f.Nhap vao n. Gan gia tri cac phan tu theo chuoi Fibonacci\n";
            do
            {
                cin >> num;
                if (num == 1 || num == 2)
                    cout << arr_fibo[0];

                for (int i = 2; i < num; i++)
                {
                    arr_fibo[i] = arr_fibo[i - 1] + arr_fibo[i - 2];
                }
                cout << "cac phan tu trong mang tuong ung \n";
                for (int i = 0; i < num; i++)
                {

                    cout << arr_fibo[i] << ", ";
                }

                if (num < 0)
                    cout << "Vui long nha lai n\n";
            } while (num < 0);

            continue;
        }

        if (!dieu_kien)
        {
            cout << "Lam a truoc!!!\n";
            continue;
        }

        if (lua_chon == 'b')
        {
            cout << "mang ban vua nhap la\n";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            continue;
        }

        if (lua_chon == 'c')
        {
            for (int i = 0; i < n; i++)
                (arr[i] % 2 == 0) ? gt_chan++ : gt_le++;
            cout << "tong so cac phan tu chan trong mang la " << gt_chan << endl
                 << "tong so cac phan tu le trong mang la " << gt_le << endl;
            continue;
        }

        if (lua_chon == 'd')
        {
            max_am = INT_MIN;
            min_duong = INT_MAX;
            bool co_duong = false;
            bool co_am = false;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] < 0)
                {
                    if (max_am < arr[i])
                        max_am = arr[i];
                    co_am = true;
                }
                else if (arr[i] > 0)
                {
                    if (min_duong >= arr[i])
                        min_duong = arr[i];
                    co_duong = true;
                }
            }

            !co_am ? cout << "khong co so am trong mang\n" : cout << "So am long nhat laf " << max_am << endl;
            !co_duong ? cout << "khong co so duong trong mang\n" : cout << "So duong be nhat la " << min_duong << endl;
            continue;
        }

        if (lua_chon == 'e')
        {
            int vi_tri_xoa;
            do
            {

                cout << "Nhap vi tri can xoa: ";
                cin >> vi_tri_xoa;
                for (int i = vi_tri_xoa; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                n--;

            } while (vi_tri_xoa < 0 && vi_tri_xoa < n);

            continue;
        }

        cout << "Xin vui long lua chon lai\n";
    }
}
