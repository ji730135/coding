#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int charToNum(char num)
{
    if (num >= '0' && num <= '9')
        return num - '0';
    else
        return num - 'A' + 10;
}

char AnumToChar(int num)
{
    if (num >= 0 && num <= 9)
        return num + '0';
    else
        return num + 'A' - 10;
}

char BnumToChar(int num)
{
    if (num >= 0 && num <= 9)
        return num + '0';
    else
        return num + 'a' - 10;
}

string conversion(int m, string a, int n)
{
    string b;
    int len = a.size();
    while (len)
    {
        int index = 0, carry = 0;
        while (index < len)
        {
            int temp = (carry * m + charToNum(a[index]));
            carry = temp % n;
            a[index] = AnumToChar(temp / n);
            index++;
        }
        index = 0;
        while (a[index] == '0')
            index++;
        a = a.substr(index);
        len = a.size();
        b += BnumToChar(carry);
    }
    reverse(b.begin(), b.end());
    int i = 0;
    while (b[i] == '0')
        i++;
    b = b.substr(i);
    return b;
}

int main()
{
    unsigned int A = 10, B = 8;
    int m;
    while (cin >> m)
    {
        if (m == 0)
            break;
        cin >> A >> B;
        unsigned int sum = A + B;
        string a = to_string(sum);
        a = conversion(10, a, m);
        if (a.size() == 0)
            a += "0";
        cout << a << endl;
    }
    return 0;
}