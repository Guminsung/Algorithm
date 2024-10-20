#include <iostream>
using namespace std;
void Baseball();

int main()
{
    ios_base::sync_with_stdio(false);
    system("cls");
    Baseball();
    return 0;
}

void Baseball()
{
    char p1[4], p2[4], c1[4], c2[4];
    cout << "Input Player1 Number : ";
    for (int i = 0; i < 4; i++)
    {
        cin >> p1[i];
    }
    system("cls");
    cout << "Input Player2 Number : ";
    for (int i = 0; i < 4; i++)
    {
        cin >> p2[i];
    }
    system("cls");
    cout << "Game Start!"
         << "\n";
    while (1)
    {
        int strike = 0, ball = 0;
        cout << "Player1 turn : ";
        for (int i = 0; i < 4; i++)
        {
            cin >> c1[i];
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (c1[i] == p2[j])
                    if (i == j)
                        strike++;
                    else
                        ball++;
            }
        }
        if (strike == 0 && ball == 0)
            cout << "out"
                 << "\n\n";
        else if (strike == 0)
            cout << ball << "ball"
                 << "\n\n";
        else if (ball == 0)
            cout << strike << "strike"
                 << "\n\n";
        else
            cout << strike << "strike"
                 << " " << ball << "ball"
                 << "\n\n";
        if (strike == 4)
        {
            cout << "Player1 Win!"
                 << "\n"
                 << "Player2 Number : ";
            for (int i = 0; i < 4; i++)
            {
                cout << p1[i];
            }
            break;
        }
        strike = 0, ball = 0;
        cout << "Player2 turn : ";
        for (int i = 0; i < 4; i++)
        {
            cin >> c2[i];
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (c2[i] == p1[j])
                    if (i == j)
                        strike++;
                    else
                        ball++;
            }
        }
        if (strike == 0 && ball == 0)
            cout << "out"
                 << "\n\n";
        else if (strike == 0)
            cout << ball << "ball"
                 << "\n\n";
        else if (ball == 0)
            cout << strike << "strike"
                 << "\n\n";
        else
            cout << strike << "strike"
                 << " " << ball << "ball"
                 << "\n\n";
        if (strike == 4)
        {
            cout << "Player2 Win!"
                 << "\n"
                 << "Player1 Number : ";
            for (int i = 0; i < 4; i++)
            {
                cout << p2[i];
            }
            break;
        }
    }
}