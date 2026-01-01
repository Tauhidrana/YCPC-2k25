#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, w;
    cin >> n >> w;

    vector<long long int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long int sum = 0;
    int l = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];

        while (sum > w && l <= i)
        {
            sum = sum - a[l];
            l++;
        }

        if (sum <= w && sum > 0 && w % sum == 0)
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}
