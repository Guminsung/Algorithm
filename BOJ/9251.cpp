#include <iostream>
using namespace std;
int LCS(string s1, string s2);
int DP[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS(s1, s2);
    return 0;
}

int LCS(string s1, string s2)
{
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
            {
                DP[i + 1][j + 1] = DP[i][j] + 1;
            }
            else if (DP[i][j + 1] > DP[i + 1][j])
                DP[i + 1][j + 1] = DP[i][j + 1];
            else
                DP[i + 1][j + 1] = DP[i + 1][j];
        }
    }
    int max = 0;
    for (int i = 1; i < s1.size() + 1; i++)
        for (int j = 1; j < s2.size() + 1; j++)
            if (max < DP[i][j])
                max = DP[i][j];
    return max;
}