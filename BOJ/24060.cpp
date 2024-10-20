#include <iostream>
using namespace std;

void merge_sort(int p, int r);
void merge(int p, int q, int r);

int A[500000];
int tmp[500000];
int k, c = 0;

int main()
{
    int n, num;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        A[i] = num;
    }
    merge_sort(0, n - 1);
    if (k > c)
        cout << -1;
    return 0;
}
void merge_sort(int p, int r)
{
    if (k != c)
    {
        if (p < r)
        {
            int q = (p + r) / 2;
            merge_sort(p, q);
            merge_sort(q + 1, r);
            merge(p, q, r);
        }
    }
}

void merge(int p, int q, int r)
{
    int i = p;
    int j = q + 1;
    int t = 0;
    while (i <= q && j <= r)
    {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }
    while (i <= q)
        tmp[t++] = A[i++];
    while (j <= r)
        tmp[t++] = A[j++];
    i = p;
    t = 0;
    while (i <= r)
    {
        A[i++] = tmp[t++];
        c++;
        if (k == c)
        {
            cout << A[i - 1];
            break;
        }
    }
}