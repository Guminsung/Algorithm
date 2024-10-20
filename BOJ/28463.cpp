#include <iostream>
using namespace std;
bool check_jump(char a[][2], char b[][2]);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char c, jump[2][2];
    char T[2][2] = {{'.', 'O'}, {'P', '.'}};
    char F[2][2] = {{'I', '.'}, {'.', 'P'}};
    char Lz[2][2] = {{'O', '.'}, {'.', 'P'}};
    bool t, f, lz;
    string s = "SWNE";
    cin >> c;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> jump[i][j];
    for (int i = 0; i < 4; i++)
        if (s[i] == c)
            for (int j = 0; j < i; j++)
            {
                int temp = jump[1][1];
                jump[1][1] = jump[1][0];
                jump[1][0] = jump[0][0];
                jump[0][0] = jump[0][1];
                jump[0][1] = temp;
            }
    t = check_jump(T, jump);
    f = check_jump(F, jump);
    lz = check_jump(Lz, jump);
    if (t)
        cout << "T";
    else if (f)
        cout << "F";
    else if (lz)
        cout << "Lz";
    else
        cout << "?";
    return 0;
}

bool check_jump(char a[][2], char b[][2])
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (a[i][j] != b[i][j])
                return false;
    return true;
}