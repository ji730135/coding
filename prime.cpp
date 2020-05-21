#include <iostream>
#include <vector>
using namespace std;
#define max_size 10000
int main()
{
    bool isPrime[max_size];
    vector<int> prime;
    // init
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < max_size; i++)
        isPrime[i] = true;
    for (int i = 2; i < max_size; i++)
    {
        if (!isPrime[i])
            continue;
        prime.push_back(i);
        for (int j = i * i; j < max_size; j += i)
            isPrime[j] = false;
    }
    int n = 0;
    while (cin >> n)
        cout << prime[n - 1] << endl;
    return 0;
}
