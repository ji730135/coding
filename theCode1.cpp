//路径打印
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**< 利用二维数组的办法，用一个vector数组，数组中每个元素是一个vector<string>数组，存放了每行的各目录，
如 a\b\c， 则vector<string> 数组中存放的是 a b c 三个string。
最后存放的结果：
a\b\c
a\d\e
b\cst
d\
{{a, b, c},
{a, d, e},
{b, cst}
{d}
}
当打印出第一行外每行的目录时，判断与前一行是否有相同的根目录，
如果有，找到第一个不同的目录，开始打印，它对应的该行的下标控制它前面有多少缩进。 */
int main()
{
    int n;
    vector<string> v, vs;
    vector<vector<string>> ve;
    while (cin >> n)
    {
        if (n == 0)
            return 0;

        string str;
        v.clear(); //存放初始的所有行
        for (int i = 0; i < n; i++)
        {
            cin >> str;
            while (str[str.length() - 1] != '\\')
                str += '\\'; //对每行进行处理，处理成最后有\字母的路径形式
            v.push_back(str);
        }
        sort(v.begin(), v.end()); //排序

        ve.clear(); //二维数组初始化
        for (int i = 0; i < v.size(); i++)
        {
            int begin = 0, end = 0;
            vs.clear(); //每个一维数组初始化
            while ((end = v[i].find("\\", begin)) != string::npos)
            {
                vs.push_back(v[i].substr(begin, end - begin));
                begin = end + 1;
            }
            ve.push_back(vs); //存放进二维数组中
        }
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && ve[i][0] == ve[i - 1][0]) //与前一个目录有相同的根目录
            {
                int j = 1;
                while (j < ve[i].size() && ve[i][j] == ve[i - 1][j])
                    j++; //找到第一个不同的目录
                for (; j < ve[i].size(); j++)
                {
                    for (int k = 0; k < j; k++)
                        cout << "  "; //j是该目录在该路径中的下标，控制缩进的次数
                    cout << ve[i][j] << endl;
                }
            }
            else
            {
                for (int j = 0; j < ve[i].size(); j++)
                {
                    for (int k = 0; k < j; k++)
                        cout << "  ";
                    cout << ve[i][j] << endl;
                }
            }
        }
        cout << endl; //每个测试用例最后都有一个空行
    }
    return 0;
}