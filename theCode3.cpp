//奥运排序问题
#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;

struct Record
{
    int id;        //0....
    int pop;       //人口数
    double ans[4]; //double gold 0; medal 1;double gp 2,mp 3;
    int rank[5];   //记录各种方式下的排名
    int sort;      //排名方式
};

int now;
bool cmp(Record a, Record b)
{
    return a.ans[now] > b.ans[now];
}

int main()
{
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF)
    {
        Record re[N];
        for (int i = 0; i < N; i++)
        {
            re[i].id = i; //数组下标即是国家id
            scanf("%lf %lf %d", &re[i].ans[0], &re[i].ans[1], &re[i].pop);
            re[i].ans[2] = (double)re[i].ans[0] / re[i].pop;
            re[i].ans[3] = (double)re[i].ans[1] / re[i].pop;
        }

        Record country[M];
        int ids[M]; //参与排名的国家
        for (int i = 0; i < M; i++)
        {
            scanf("%d", &ids[i]); //输入参与排名的国家id
            country[i] = re[ids[i]];
            country[i].rank[4] = INT_MAX;
        }

        for (now = 0; now < 4; now++)
        {
            sort(country, country + M, cmp); //排序

            country[0].rank[now] = 1;
            if (country[0].rank[now] < country[0].rank[4])
            {
                country[0].rank[4] = 1;
                country[0].sort = now + 1;
            }
            for (int i = 1; i < M; i++) //定级
            {
                if (country[i].ans[now] == country[i - 1].ans[now]) //总数相同
                    country[i].rank[now] = country[i - 1].rank[now];
                else
                    country[i].rank[now] = i + 1;

                if (country[i].rank[now] < country[i].rank[4])
                {
                    country[i].rank[4] = country[i].rank[now];
                    country[i].sort = now + 1;
                }
            }
        }

        for (int i = 0; i < M; i++) //将修改改回原始数组，方便按照输入顺序输出
        {
            re[country[i].id] = country[i];
        }

        for (int i = 0; i < M; i++)
        {
            printf("%d:%d\n", re[ids[i]].rank[4], re[ids[i]].sort);
        }

        printf("\n");
    }
    return 0;
}