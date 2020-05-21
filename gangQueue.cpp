#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int N = 0;
    while (cin >> N)
    {
        vector<int> stus(N);
        for (int i = 0; i < N; i++)
            cin >> stus[i];
        int K = 0;
        for (int k = 0; k < N; k++)
        {
            vector<int> Ldp(N, 1), Rdp(N, 1);
            for (int m = 1; m <= k; m++)
            {
                for (int n = 0; n < m; n++)
                {
                    if (stus[m] > stus[n])
                        Ldp[m] = max(Ldp[n] + 1, Ldp[m]);
                }
            }
            for (int m = N - 2; m >= k; m--)
            {
                for (int n = m + 1; n < N; n++)
                {
                    if (stus[m] > stus[n])
                        Rdp[m] = max(Rdp[n] + 1, Rdp[m]);
                }
            }
            K = max(Ldp[k] + Rdp[k] - 1, K);
        }
        cout << N - K << endl;
    }
    return 0;
}
