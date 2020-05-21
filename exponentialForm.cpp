#include <iostream>
#include <string>
using namespace std;

string exponential(int n)
{
    string str;
    if (n == 0)
    {
        str = "";
        return str;
    }
    if (n == 1)
    {
        str = "2(0)";
        return str;
    }
    else if (n == 2)
    {
        str = "2";
        return str;
    }
    int temp = 2, k = 0;
    while (temp <= n)
    {
        temp = temp * 2;
        k++;
    }
    if (k != 1)
        str = "2(" + exponential(k) + ")";
    else
        str = "2";
    if (n - temp / 2 != 0)
        str = str + "+" + exponential(n - temp / 2);
    return str;
}

int main()
{
    int n;
    while (cin >> n)
    {
        string str = exponential(n);
        cout << str << endl;
    }
    return 0;
}