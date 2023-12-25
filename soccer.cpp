#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string fullnames[] = {"Bui Hoang Viet Anh",
                      "Bui Tan Truong",
                      "Bui Tien Dung",
                      "Do Duy Manh",
                      "Doan Van Hau",
                      "Ha Duc Chinh",
                      "Ho Tan Tai",
                      "Ho Tuan Tai",
                      "Le Tien Anh",
                      "Le Van Xuan",
                      "Luong Xuan Truong",
                      "Ly Cong Hoang Anh",
                      "Nguyen Hoang Duc",
                      "Nguyen Phong Hong Duy",
                      "Nguyen Quang Hai",
                      "Nguyen Thanh Binh",
                      "Nguyen Thanh Chung",
                      "Nguyen Tien Linh",
                      "Nguyen Trong Hoang",
                      "Nguyen Tuan Anh",
                      "Nguyen Van Hoang",
                      "Nguyen Van Toan",
                      "Pham Duc Huy",
                      "Pham Tuan Hai",
                      "Phan Van Duc",
                      "Que Ngoc Hai",
                      "Tran Dinh Trong",
                      "Tran Minh Vuong",
                      "Truong Van Thiet",
                      "Vu Van Thanh"};
string positions[] = {
    "Hau ve",
    "Thu mon",
    "Hau ve",
    "Hau ve",
    "Hau ve",
    "Tien dao",
    "Hau ve",
    "Tien dao",
    "Tien ve",
    "Hau ve",
    "Tien ve",
    "Tien ve",
    "Tien ve",
    "Hau ve",
    "Tien ve",
    "Hau ve",
    "Hau ve",
    "Tien dao",
    "Hau ve",
    "Tien ve",
    "Thu mon",
    "Tien dao",
    "Tien ve",
    "Tien dao",
    "Tien ve",
    "Hau ve",
    "Hau ve",
    "Tien ve",
    "Hau ve",
    "Hau ve"};
int numbers[] = {
    34, 24, 4, 2, 5, 18, 35, 10, 11, 27, 6, 33, 14, 7, 19,
    31, 16, 22, 8, 11, 25, 9, 15, 10, 20, 3,
    21, 26, 5, 17};
string clubs[] = {
    "CLB Ha Noi",
    "CLB Ha Noi",
    "CLB Viettel",
    "CLB Ha Noi",
    "CLB Ha Noi",
    "CLB SHB Da Nang",
    "CLB Binh Dinh",
    "CLB Thanh pho Ho Chi Minh",
    "CLB Topenland Binh Dinh",
    "CLB Ha Noi",
    "CLB Hoang Anh Gia Lai",
    "CLB Hong Linh Ha Tinh",
    "CLB Viettel",
    "CLB Hoang Anh Gia Lai",
    "CLB Ha Noi",
    "CLB Viettel",
    "CLB Ha Noi",
    "CLB Becamex Binh Duong",
    "CLB Viettel",
    "CLB Hoang Anh Gia Lai",
    "CLB Song Lam Nghe An",
    "CLB Hoang Anh Gia Lai",
    "CLB Ha Noi",
    "CLB Hong Linh Ha Tinh",
    "CLB Song Lam Nghe An",
    "CLB Viettel",
    "CLB Ha Noi",
    "CLB Hoang Anh Gia Lai",
    "CLB Viettel",
    "CLB Hoang Anh Gia Lai"

};

int total_available_players = sizeof(positions) / sizeof(positions[0]);

void print_player(int index)
{
    cout << fullnames[index] << " - " << positions[index] << " - " << numbers[index]
         << " - " << clubs[index] << endl;
}

void print_players(int indexes[], int n, string title)
{
    cout << title << endl;
    for (int i = 0; i < n; i++)
    {
        print_player(indexes[i]);
    }
}

int main()
{
    srand(time(NULL));
    int curr_num_gk = 0;
    int curr_num_defenders = 0;
    int curr_num_midfielders = 0;
    int curr_num_attackers = 0;

    // Find the number of each position for declare arrays bellow
    for (int i = 0; i < total_available_players; i++)
    {
        if (positions[i] == "Thu mon")
            curr_num_gk++;
        else if (positions[i] == "Hau ve")
            curr_num_defenders++;
        else if (positions[i] == "Tien ve")
            curr_num_midfielders++;
        else
            curr_num_attackers++;
    }

    int gk_indexes[curr_num_gk], defender_indexes[curr_num_defenders];
    int midfielder_indexes[curr_num_midfielders], attacker_indexes[curr_num_attackers];

    // Filter
    for (
        int i = 0, idx_gk = 0, idx_def = 0, idx_mid = 0, idx_att = 0;
        i < total_available_players;
        i++)
    {
        if (positions[i] == "Thu mon")
            gk_indexes[idx_gk++] = i;
        else if (positions[i] == "Hau ve")
            defender_indexes[idx_def++] = i;
        else if (positions[i] == "Tien ve")
            midfielder_indexes[idx_mid++] = i;
        else
            attacker_indexes[idx_att++] = i;
    }

    // Available data: gk_indexes[curr_num_gk], defender_indexes[curr_num_defenders];
    // midfielder_indexes[curr_num_midfielders], attacker_indexes[curr_num_attackers];

    // User requests
    int num_defenders, num_midfielders, num_attackers;

    cout << "Enter the number of defenders\n> ";
    cin >> num_defenders;
    cout << "Enter the number of midfileders\n> ";
    cin >> num_midfielders;
    cout << "Enter the number of attackers\n> ";
    cin >> num_attackers;

    // Pick random 1 GK in gk_indexes[curr_num_gk]
    int random_idx = rand() % curr_num_gk;
    int final_gk_index = gk_indexes[random_idx];

    // Pick random `num_defenders` DEFs in defender_indexes[curr_num_defenders]
    int final_def_indexes[num_defenders];
    for (int i = 0; i < num_defenders; i++)
    {
        while (true)
        {
            int random_idx = rand() % curr_num_defenders;
            int selected = defender_indexes[random_idx];
            bool existed = false;

            // Check if valid or not
            for (int j = 0; j < i; j++)
            {
                if (final_def_indexes[j] == selected)
                {
                    existed = true;
                    break;
                }
            }

            if (!existed)
            {
                final_def_indexes[i] = selected;
                break;
            }
        }
    }

    // Pick random `num_midfielders` DEFs in midfielder_indexes[curr_num_midfielders]
    int final_mid_indexes[num_midfielders];
    for (int i = 0; i < num_midfielders; i++)
    {
        while (true)
        {
            int random_idx = rand() % curr_num_midfielders;
            int selected = midfielder_indexes[random_idx];
            bool existed = false;

            // Check if valid or not
            for (int j = 0; j < i; j++)
            {
                if (final_mid_indexes[j] == selected)
                {
                    existed = true;
                    break;
                }
            }

            if (!existed)
            {
                final_mid_indexes[i] = selected;
                break;
            }
        }
    }

    // Pick random `num_attackers` DEFs in attacker_indexes[curr_num_attackers]
    int final_att_indexes[num_attackers];
    for (int i = 0; i < num_attackers; i++)
    {
        while (true)
        {
            int random_idx = rand() % curr_num_attackers;
            int selected = attacker_indexes[random_idx];
            bool existed = false;

            // Check if valid or not
            for (int j = 0; j < i; j++)
            {
                if (final_att_indexes[j] == selected)
                {
                    existed = true;
                    break;
                }
            }

            if (!existed)
            {
                final_att_indexes[i] = selected;
                break;
            }
        }
    }

    cout << "Thu mon\n";
    print_player(final_gk_index);
    print_players(final_def_indexes, num_defenders, "Hau ve");
    print_players(final_mid_indexes, num_midfielders, "Tien ve");
    print_players(final_att_indexes, num_attackers, "Tien dao");
}