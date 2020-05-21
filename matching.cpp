#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        for (int k = 0; k < n; k++)
        {
            stack<char> s;
            string str;
            cin >> str;
            int len = str.size();
            bool flag = true;
            for (int i = 0; i < len; i++)
            {
                char temp = str[i];
                if (temp == '(' || temp == '[' || temp == '{')
                    s.push(temp);
                else if (temp == ')' || temp == ']' || temp == '}')
                {
                    if (s.empty())
                    {
                        flag = false;
                        break;
                    }
                    char top = s.top();
                    s.pop();
                    if ((temp == ')' && top == '(') || (temp == ']' && top == '[') || (temp == '}' && top == '{'))
                        continue;
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (!s.empty())
                flag = false;
            if (flag)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}