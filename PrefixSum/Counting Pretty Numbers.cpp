#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        if (i % 10 == 2 || i % 10 == 3 || i % 10 == 9)
        {
            ans++;
        }
    }
    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
