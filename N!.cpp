#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN 500
// 实现99以内的阶乘
int main()
{
    int n;
    while (cin >> n)
    {
        int number[MAXN], len_num, ans[MAXN], len_ans;
        fill(number, number + MAXN, 0);
        number[0] = 1;
        len_num = 1;
        for (int k = 1; k < n + 1; k++)
        {
            fill(ans, ans + MAXN, 0);
            len_ans = len_num + 2;
            int low = k % 10, high = k / 10;
            for (int i = 0; i < len_num; i++)
            {
                ans[i] += number[i] * low;
                ans[i + 1] += number[i] * high;
            }
            int carry = 0, temp;
            for (int i = 0; i < len_ans; i++)
            {
                temp = ans[i] + carry;
                ans[i] = temp % 10;
                carry = temp / 10;
            }
            while (ans[len_ans - 1] == 0 && len_ans > 1)
                len_ans--;
            fill(number, number + MAXN, 0);
            for (int i = 0; i < len_ans; i++)
                number[i] = ans[i];
            len_num = len_ans;
        }
        for (int i = len_num - 1; i >= 0; i--)
            cout << number[i];
        cout << endl;
    }
    return 0;
}