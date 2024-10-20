#include <iostream>
using namespace std;
int v[100002];
void heap(int n);
int c = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
    for (int i = 0; i < 100002; i++)
    {
        v[i] = 2147483647;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        heap(num);
    }
    return 0;
}

void heap(int n)
{
    if (n == 0)
    {
        if (c > 0)
        {
            cout << v[1] << "\n";
            v[1] = v[c];
            v[c--] = 2147483647;
            int index = 1;
            while (index * 2 <= c)
            {
                int index2, abs1 = v[index * 2], abs2 = v[index * 2 + 1];
                if (abs1 < 0)
                    abs1 = -abs1;
                if (abs2 < 0)
                    abs2 = -abs2;
                if (abs1 < abs2)
                    index2 = index * 2;
                else if (abs1 == abs2)
                {
                    if (v[index * 2] < v[index * 2 + 1])
                        index2 = index * 2;
                    else
                        index2 = index * 2 + 1;
                }
                else
                    index2 = index * 2 + 1;
                int abs3 = v[index], abs4 = v[index2];
                if (abs3 < 0)
                    abs3 = -abs3;
                if (abs4 < 0)
                    abs4 = -abs4;
                if (abs3 > abs4)
                {
                    int temp = v[index];
                    v[index] = v[index2];
                    v[index2] = temp;
                    index = index2;
                }
                else if (abs3 == abs4)
                {
                    if (v[index] > v[index2])
                    {
                        int temp = v[index];
                        v[index] = v[index2];
                        v[index2] = temp;
                        index = index2;
                    }
                    else
                        break;
                }
                else
                    break;
            }
        }
        else
            cout << 0 << "\n";
    }
    else
    {
        v[++c] = n;
        int index = c;
        while (index / 2 > 0)
        {
            int abs1 = v[index], abs2 = v[index / 2];
            if (abs1 < 0)
                abs1 = -abs1;
            if (abs2 < 0)
                abs2 = -abs2;
            if (abs1 < abs2)
            {
                int temp = v[index];
                v[index] = v[index / 2];
                v[index / 2] = temp;
                index /= 2;
            }
            else if (abs1 == abs2)
            {
                if (v[index] < v[index / 2])
                {
                    int temp = v[index];
                    v[index] = v[index / 2];
                    v[index / 2] = temp;
                    index /= 2;
                }
                else
                    break;
            }
            else
                break;
        }
    }
}