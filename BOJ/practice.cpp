#include <string>
#include <vector>
int s[1000001], e[1000001];
int mx = 0;

using namespace std;

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer;
    int node = 0, count, circle = 0, stick = 0, clip = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        mx = max(mx, edges[i][0]);
        mx = max(mx, edges[i][1]);
        s[edges[i][0]]++;
        e[edges[i][1]]++;
    }
    for (int i = 1; i <= mx; i++)
    {
        if (!node && s[i] >= 2)
            if (e[i] == 0)
            {
                node = i;
                count = s[i];
            }
            else
                clip++;
        else if (s[i] == 2)
            clip++;
        else if (s[i] == 0)
            stick++;
    }
    circle = count - clip - stick;
    answer.push_back(node);
    answer.push_back(circle);
    answer.push_back(stick);
    answer.push_back(clip);
    return answer;
}
