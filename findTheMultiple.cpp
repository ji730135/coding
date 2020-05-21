#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long mod[1000000];
int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        for (int i = 1;; i++)
        {                                     //这里要从1开始，为什么看下面
            mod[i] = mod[i / 2] * 10 + i % 2; //这是关键语句，实际上和上一个代码的深搜是一个道理，只不过用循环代替了，很巧妙，我们来分析一下
            //因为每次只有两个操作，所以第i个数，应该由第i/2个数*10或者*10+1得到，
            //因为每次都要乘十，所以每次都乘，只不过就是加一或者不加的问题
            //这里就巧妙用到下标奇偶性质，奇数模2为1，就相当与加一，而偶数相当于不加，所以下标从1开始是方便的，
            //你可能问开始的两个加一或不加会不会出现零，因为题目要求不能出现
            //零，不会，因为第一个是1，第二个发现虽然不加1但是2/2=1了所以第二个元素还是1，所以从下标1开始很神奇！
            if (mod[i] % n == 0)
            {
                printf("%lld\n", mod[i]);
                break;
            }
        }
    }
    return 0;
}