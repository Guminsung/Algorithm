#include <iostream>
#include <time.h>
using namespace std;
void Rotto();

int main()
{
    system("cls");
    Rotto();
    return 0;
}

void Rotto()
{
    int v[45], idx1, idx2, temp;
    for (int i = 0; i < 45; i++)
    {
        v[i] = i + 1;
    }
    srand((unsigned int)time(NULL));
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 100; i++)
        {
            idx1 = rand() % 45;
            idx2 = rand() % 45;
            temp = v[idx1];
            v[idx1] = v[idx2];
            v[idx2] = temp;
        }
        for (int i = 0; i < 6; i++)
        {
            cout << v[i] << "\t";
        }
        cout << "\n";
    }
}