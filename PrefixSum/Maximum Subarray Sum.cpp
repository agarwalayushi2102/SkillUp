#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
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
    long long int mn = sm[0];
    long long int mx = sm[1];
    for (long long int i = 1; i < n + 1; i++)
    {

        mx = max(mx, sm[i] - mn);
        mn = min(mn, sm[i]);
    }

    cout << mx << '\n';

    return 0;
}