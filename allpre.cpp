#include <iostream>
#include <algorithm>
using namespace std;

bool visit[20];
int weights[20], n;
int style = 0;
bool cmp(int a, int b)
{
    return a > b;
}

void dfs(int amn, int cur)
{
    if (amn == 40)
    {
        style++;
        return;
    }
    for (int k = cur; k < n; k++)
    {
        if (amn + weights[k] > 40 || visit[k])
            continue;
        visit[k] = true;
        dfs(amn + weights[k], k + 1);
        visit[k] = false;
    }
    return;
}

int main()
{
    cin >> n;
    for (int k = 0; k < n; k++)
        cin >> weights[k];
    sort(weights, weights + n, cmp);
    fill(visit, visit + n, false);
    dfs(0, 0);
    cout << style << endl;
    return 0;
}