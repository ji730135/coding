#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        getchar();
        vector<string> lib(n);
        string temp, pat;
        for (int i = 0; i < n; i++)
        {
            getline(cin, temp);
            lib[i] = temp;
        }
        getline(cin, pat);
        for (int i = 0; i < pat.size(); i++)
        {
            if (pat[i] >= 'A' && pat[i] <= 'Z')
                pat[i] = pat[i] - 'A' + 'a';
        }
        int b, e;
        b = pat.find('[');
        e = pat.find(']');
        string gene = pat.substr(b + 1, e - b - 1);
        pat.erase(b, e - b + 1);
        for (int k = 0; k < gene.size(); k++)
        {
            pat.insert(pat.begin() + b, gene[k]);
            for (int i = 0; i < n; i++)
            {
                temp = lib[i];
                for (int t = 0; t < temp.size(); t++)
                {
                    if (temp[t] >= 'A' && temp[t] <= 'Z')
                        temp[t] = temp[t] - 'A' + 'a';
                }
                if (temp.find(pat) != string::npos)
                    cout << i + 1 << ' ' << lib[i] << endl;
            }
            pat.erase(b, 1);
        }
    }
    return 0;
}
