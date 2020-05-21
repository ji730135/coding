#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
    int m;
    scanf("%d", &m);
    while (m--)
    {
        int cx, cy, cz, ex, ey, ez;
        scanf("%d %d %d %d %d %d", &cx, &cy, &cz, &ex, &ey, &ez);
        double r = sqrt(pow(cx - ex, 2) + pow(cy - ey, 2) + pow(cz - ez, 2));
        double v = 4 * 3.1415926 * pow(r, 3) / 3.0;
        printf("%.2lf %.2lf\n", r, v);
    }
}