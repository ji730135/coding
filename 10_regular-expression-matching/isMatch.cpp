/*这段代码只能通过部分样例，归根结底是理解正则表达式出了问题
#include <string>
using namespace std;

//主串和模式串从后往前匹配
//若模式字符为a-z字母，则比较游标指向的字符，主串和模式串同步向前移动游标；
//若模式字符为.则主串游标直接前移一位，不用管主串对应字符具体为何，模式串游标同样前移一位，继续接下来的比较；
//若模式字符为*，则在主串不越界的情况下不断向前移动主串游标直到不是相同的字符。
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int sIndex = s.length() - 1, pIndex = p.length() - 1;
        while (sIndex >= 0 && pIndex >= 0)
        {
            if (s[sIndex] == p[pIndex] || p[pIndex] == '.')
            {
                sIndex--;
                pIndex--;
            }
            else if (p[pIndex] == '*')
            {
                while (sIndex > 0 && s[sIndex] == s[sIndex - 1])
                    sIndex--;
                pIndex--;
            }
            else
                return false;
        }
        while (p[pIndex] == '*')
            pIndex--;
        if (sIndex < 0 && pIndex < 0
        )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    string s = {"ab"};
    string p = {".*"};
    Solution solution;
    bool is_ = solution.isMatch(s, p);
    return 0;
}
*/
