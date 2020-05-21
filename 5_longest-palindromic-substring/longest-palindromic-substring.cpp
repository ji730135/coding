#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int max = 0, left = 0;
        int len_s = s.length();
        for (int center = 1; center < 2 * len_s; center++)
        {
            int temp = palindromeLength(s, center);
            if (max < temp)
            {
                max = temp;
                left = (center - max) / 2;
            }
        }
        return s.substr(left, max);
    }
    int palindromeLength(string s, int center)
    {
        int left = center / 2 - 1, right = (center - 1) / 2 + 1;
        int len_s = s.length();

        while (left >= 0 && right < len_s && s[left] == s[right])
        {
            left = left - 1;
            right = right + 1;
        }
        return (right - left - 1);
    }
};

int main()
{
    string s = {"babad"};
    Solution solution;
    string sub = solution.longestPalindrome(s);
    return 0;
}
