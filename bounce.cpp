#include <stdio.h>

int main()
{
    int m;
    scanf("%d", &m);
    while (m--)
    {
        double H;
        int n;
        scanf("%lf%d", &H, &n);
        double dist = H;
        while (--n)
        {
            dist += H;
            H = H / 2;
        }
        printf("%.2lf\n", dist);
    }
    return 0;
}