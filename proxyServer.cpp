#include <cstdio>
#include <cstring>

int main()
{
    int n, m;
    char client[1000][16], server[5000][16];
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%s", client[i]);
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
            scanf("%s", server[i]);

        int sIndex = 0, times = -1;
        bool flag = true;
        while (flag && sIndex < m)
        {
            int j, max = 0;
            for (int i = 0; i < n; i++)
            {
                for (j = sIndex; j < m; j++)
                {
                    if (strcmp(client[i], server[j]) == 0)
                    {
                        if (n == 1)
                            flag = false;
                        break;
                    }
                }
                if (j - sIndex > max)
                    max = j - sIndex;
            }
            sIndex += max;
            times++;
        }
        if (flag)
            printf("%d\n", times);
        else
            printf("-1\n");
    }
    return 0;
}