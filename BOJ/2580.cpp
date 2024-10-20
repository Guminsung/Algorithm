#include <iostream>
#include <vector>
using namespace std;

void sdoku(int n);
bool check(int r, int c);

int puzzle[9][9];
vector<pair<int, int>> v;
int finish = 0;
bool found = false;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> num;
            puzzle[i][j] = num;
            if (num == 0)
            {
                v.push_back(make_pair(i, j));
                finish++;
            }
        }
    }
    sdoku(0);
    return 0;
}

void sdoku(int n)
{
    if (n < finish)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (found == true)
                break;
            puzzle[v[n].first][v[n].second] = i;
            if (check(v[n].first, v[n].second) == true)
                sdoku(n + 1);
        }
        puzzle[v[n].first][v[n].second] = 0;
    }
    else
    {
        found = true;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << puzzle[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

bool check(int r, int c)
{
    for (int i = 0; i < 9; i++)
    {
        if ((puzzle[r][c] == puzzle[r][i] && c != i) || (puzzle[r][c] == puzzle[i][c] && r != i))
            return false;
    }
    int sr = (r / 3) * 3, sc = (c / 3) * 3;
    for (int i = sr; i < sr + 3; i++)
    {
        for (int j = sc; j < sc + 3; j++)
        {
            if (puzzle[r][c] == puzzle[i][j] && (r != i || c != j))
                return false;
        }
    }
    return true;
}