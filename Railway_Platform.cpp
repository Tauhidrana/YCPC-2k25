#include <bits/stdc++.h>
using namespace std;

long long merge_count(vector<long long int> &a, int l, int r)
{
    if (l >= r)
        return 0;

    int mid = (l + r) / 2;
    long long cnt = 0;

    cnt += merge_count(a, l, mid);
    cnt += merge_count(a, mid + 1, r);

    vector<long long int> temp;
    int i = l, j = mid + 1;

    while (i <= mid && j <= r)
    {
        if (a[i] >= a[j])
        {
            cnt += (r - j + 1);
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(a[i++]);
    }
    while (j <= r)
    {
        temp.push_back(a[j++]);
    }

    for (int k = 0; k < temp.size(); k++)
    {
        a[l + k] = temp[k];
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<long long int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long ans = merge_count(a, 0, n - 1);
        cout << ans << endl;
    }
}
