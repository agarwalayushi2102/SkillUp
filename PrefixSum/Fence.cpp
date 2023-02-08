#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v, sm;
    sm.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int p, ans;
    for (int i = 1; i <= n; i++)
    {
        sm.push_back(v[i - 1] + sm[i - 1]);
    }
    int mn = sm[n]+1;
    for (int i = 0; i < (sm.size() - k); i++)
    {
        p = sm[i + k] - sm[i];
        if (p < mn)
        {
            ans = i;
            mn = p;
        }
    }
    cout << ans+1 << '\n';
    return 0;
}