#include <iostream>
using namespace std;

int number[11];
int character[4];
int sum[11];
void back_tracking(int p, int n);
int calculate(int a, int b, int c);
int s_max = -1000000001, s_min = 1000000001;

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
        number[i] = num;
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> num;
        character[i] = num;
    }
    sum[0] = number[0];
    back_tracking(0, n);
    cout << s_max << "\n"
         << s_min;
    return 0;
}

void back_tracking(int p, int n)
{
    if (p == n - 1)
    {
        if (s_max < sum[p])
            s_max = sum[p];
        if (s_min > sum[p])
            s_min = sum[p];
    }
    for (int i = 0; i < 4; i++)
    {
        if (character[i] == 0)
            continue;
        sum[p + 1] = calculate(sum[p], number[p + 1], i + 1);
        character[i]--;
        back_tracking(p + 1, n);
        character[i]++;
    }
}

int calculate(int a, int b, int c)
{
    int result;
    switch (c)
    {
    case 1:
        result = a + b;
        break;
    case 2:
        result = a - b;
        break;
    case 3:
        result = a * b;
        break;
    case 4:
        result = a / b;
    }
    return result;
}