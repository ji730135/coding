#include <stack>
#include <string>
using namespace std;

//若栈空且字符串遍历完毕，则括号字符串有效；
//若当前所扫描括号为({左括号，则入栈；
//若当前所扫描括号为)}右括号，则出栈栈顶括号并判断是否匹配。若不匹配则括号字符串无效，若匹配则重复上述过程。
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> filo;
        int cur = 0;
        while (!filo.empty() || cur != s.length())
        {
            char tmp = s[cur];
            if (tmp == '(' || tmp == '{' || tmp == '[')
                filo.push(tmp);
            else
            {
                if (!filo.empty())
                {
                    char top = filo.top();
                    filo.pop();
                    if ((tmp != ')' || top != '(') && (tmp != '}' || top != '{') && (tmp != ']' || top != '['))
                        return false;
                }
                else
                    return false;
            }
            cur += 1;
        }
        return true;
    }
};

int main()
{
    string s = {"]"};
    Solution solution;
    bool is_ = solution.isValid(s);
    return 0;
}
