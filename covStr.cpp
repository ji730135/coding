#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int convert(char s, char d)
{
    int dis = abs(s - d);
    return min(26 - dis, dis);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        char str[101];
        cin >> str;
        int len = strlen(str);
        sort(str, str + len);
        //去重
        char base[26], temp = '0';
        int size = 0;
        for (int k = 0; k < len; k++)
        {
            if (temp != str[k])
            {
                temp = str[k];
                base[size++] = temp;
            }
        }
        int min = INT_MAX;
        for (int k = 0; k < size; k++)
        {
            int temp = 0;
            for (int m = 0; m < len; m++)
                temp += convert(str[m], base[k]);
            if (temp < min)
                min = temp;
        }
        cout << min << endl;
    }
    return 0;
}