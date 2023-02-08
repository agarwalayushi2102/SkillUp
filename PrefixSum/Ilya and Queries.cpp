#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int m;
    cin >> m;
    int l = s.length();
    vector<int> ans(l, 0);
    int c = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            c++;
        }
        ans[i] = c;
    }
    
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        int a;
        a = ans[r - 1] - ans[l - 1];
        if (a < 0)
            a = 0;
        cout << a << '\n';
    }

    return 0;
}