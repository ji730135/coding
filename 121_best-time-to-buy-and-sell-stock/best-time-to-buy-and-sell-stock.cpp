#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = INT_MAX, sell = INT_MAX, earn = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] - buy > earn)
            {
                sell = prices[i];
                earn = sell - buy;
            }
            if (prices[i] < buy)
                buy = prices[i];
        }
        return earn;
    }
};

int main()
{
    vector<int> s = {7, 6, 4, 3, 1};
    Solution solution;
    int res = solution.maxProfit(s);
    return 0;
}
