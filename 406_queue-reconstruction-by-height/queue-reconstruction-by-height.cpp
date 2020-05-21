#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] != b[0])
            return a[0] > b[0];
        return a[1] < b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> ans;
        if (people.size() == 0)
            return ans;
        sort(people.begin(), people.end(), cmp);
        for (auto person : people)
        {
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;
    }
};