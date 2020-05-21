#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}

bool visit[20];
int weights[20], n;

int dfs(int amn, int cur, int style)
{
    if (amn == 40)
        return style;

    for (int k = cur; k < n; k++)
    {
        if (amn + weights[cur] > 40 || visit[cur])
            continue;
        visit[k] = true;
        if (amn + weights[cur] == 40)
            style++;
        else
        {
            style += dfs(amn + weights[cur], cur + 1, style);
        }
        visit[k] = false;
    }
    return 0;
}

int main()
{
    cin >> n;
    for (int k = 0; k < n; k++)
        cin >> weights[k];
    sort(weights, weights + n, cmp);
    fill(visit, visit + n, false);
    int style = dfs(0, 0, 0);
    cout << style << endl;
    return 0;
}