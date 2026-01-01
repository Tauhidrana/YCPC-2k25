#include <bits/stdc++.h>
using namespace std;

long long cnt_bits(long long n)
{
    long long c = 0;
    while (n)
    {
        if (n & 1)
            c++;
        n >>= 1;
    }
    return c;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        long long x;
        cin >> x;

        if (x == 0)
        {
            cout << 1 << "\n";
            continue;
        }
        else
        {

            long long k = cnt_bits(x);
            long long ans = 1LL << (k - 1);
            cout << ans << "\n";
        }
    }
}
