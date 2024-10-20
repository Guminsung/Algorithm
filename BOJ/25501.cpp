#include <iostream>
using namespace std;
int num;

int recursion(string &s, int l, int r, int c) {
    if (l >= r)
    {
        num = c;
        return 1;
    }
    else if (s[l] != s[r])
    {
        num = c;
        return 0;
    }
    else return recursion(s, l + 1, r - 1, c + 1);
}

int isPalindrome(string &s) {
    return recursion(s, 0, s.size() - 1, 1);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        r = isPalindrome(s);
        cout << r << " " << num << "\n";
    }
    return 0;
}