#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;
struct S
{
    string str;
    int level;
};
int main()
{
    S s;
    string pattern = "2012";
    int N;
    while (cin >> N >> s.str)
    {
        if (N < 4)
            cout << -1 << endl;
        else
        {
            s.level = 0;
            map<string, int> domain;
            queue<S> q;
            q.push(s);
            bool flag = false;
            while (!q.empty())
            {
                S temp = q.front();
                q.pop();
                if (temp.str.find(pattern) != string::npos)
                {
                    cout << temp.level << endl;
                    flag = true;
                    break;
                }
                domain[temp.str]++;
                S next;
                for (int i = 0; i + 1 < temp.str.size(); i++)
                {
                    next = temp;
                    swap(next.str[i], next.str[i + 1]);
                    if (domain[next.str] == 0)
                    {
                        next.level++;
                        q.push(next);
                    }
                }
            }
            if (!flag)
                cout << -1 << endl;
        }
    }
    return 0;
}
