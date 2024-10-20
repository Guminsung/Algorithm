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
            v[c--] = 0;
            int index = 1;
            while (index * 2 <= c)
            {
                int index2;
                if (v[index * 2] > v[index * 2 + 1])
                    index2 = index * 2;
                else
                    index2 = index * 2 + 1;
                if (v[index] < v[index2])
                {
                    int temp = v[index];
                    v[index] = v[index2];
                    v[index2] = temp;
                    index = index2;
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
            if (v[index] > v[index / 2])
            {
                int temp = v[index];
                v[index] = v[index / 2];
                v[index / 2] = temp;
                index /= 2;
            }
            else
                break;
        }
    }
}