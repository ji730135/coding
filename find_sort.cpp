#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct stu
{
    string name;
    int score;
    stu(string a, int b) : name(a), score(b) {}
};
bool desc(const stu &a, const stu &b)
{
    return a.score > b.score;
}

bool aesc(const stu &a, const stu &b)
{
    return a.score < b.score;
}

int main()
{
    int num, flag = 0;
    while (cin >> num >> flag)
    {
        string name;
        int score;
        vector<stu> group;
        while (num--)
        {
            cin >> name >> score;
            group.push_back(stu(name, score));
        }
        if (flag == 0)
            stable_sort(group.begin(), group.end(), desc);
        else
            stable_sort(group.begin(), group.end(), aesc);
        for (auto it = group.begin(); it != group.end(); it++)
            cout << it->name << " " << it->score << endl;
    }
    return 0;
}