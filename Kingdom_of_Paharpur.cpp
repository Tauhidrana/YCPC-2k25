#include <bits/stdc++.h>
using namespace std;

long long find_silent(vector<long long> &h, int l, int r)
{
    if (l > r)
        return 0;

    int max_pos = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (h[i] > h[max_pos])
        {
            max_pos = i;
        }
    }

    bool unique_max = true;
    for (int i = l; i <= r; i++)
    {
        if (i != max_pos && h[i] == h[max_pos])
        {
            unique_max = false;
            break;
        }
    }

    if (unique_max == false)
    {
        return 0;
    }

    bool climb = true;
    for (int i = l; i < max_pos; i++)
    {
        if (h[i] > h[i + 1])
        {
            climb = false;
            break;
        }
    }

    bool descent = true;
    for (int i = max_pos; i < r; i++)
    {
        if (h[i] < h[i + 1])
        {
            descent = false;
            break;
        }
    }

    return (climb && descent) ? 1 : 0;
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<long long> h(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        long long ans = find_silent(h, l, r);
        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
