#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct tran
{
    int num;
    int time;
    int sTime;
    int tips;
    tran()
    {
        time = 0;
        tips = 0;
    };
};

int toMinutes(string time)
{
    int minutes = ((char)time[0] - '0') * 600 + ((char)time[1] - '0') * 60 +
                  ((char)time[3] - '0') * 10 + ((char)time[4] - '0');
    return minutes;
}

int main()
{
    int num;
    char type;
    string time;
    vector<tran> trans;
    while (cin >> num)
    {
        if (num == -1)
            break;
        cin >> type >> time;
        if (num == 0)
        {
            int amn = 0, len = trans.size(), valid_trans = 0;
            for (int k = 0; k < len; k++)
            {
                if (trans[k].tips % 2 == 0)
                {
                    amn += trans[k].time;
                    valid_trans++;
                }
            }
            if (valid_trans == 0)
                cout << "0 " << valid_trans << endl;
            else
                cout << valid_trans << ' ' << round(amn * 1.0 / valid_trans) << endl;
            trans.clear();
            continue;
        }

        int len = trans.size();
        tran temp;
        if (type == 'S')
        {
            for (int k = 0; k <= len; k++)
            {
                if (k == len)
                {
                    temp.num = num;
                    temp.sTime = toMinutes(time);
                    temp.tips = 1;
                    trans.push_back(temp);
                    break;
                }
                temp = trans[k];
                if (temp.num == num && temp.tips % 2 == 0)
                {
                    temp.sTime = toMinutes(time);
                    temp.tips++;
                    break;
                }
            }
        }
        else
        {
            for (int k = 0; k < len; k++)
            {
                temp = trans[k];
                if (temp.num == num && temp.tips % 2 == 1)
                {
                    trans[k].time += (toMinutes(time) - temp.sTime);
                    trans[k].tips++;
                    break;
                }
            }
        }
    }
    return 0;
}