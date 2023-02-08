#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, q;
    cin >> n >> q;
    vector<long long int> v, sm(n + 1, 0);
    for (long long int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sm.push_back(0);
    for (long long int i = 0; i < n; i++)
    {
        sm[i + 1] = sm[i] + v[i];
    }
    while (q--)
    {
        long long int l, r;
        cin >> l >> r;
        long long int ans;
        ans = sm[r] - sm[l];
        cout << ans << '\n';
    }
    return 0;
}
