#include <bits/stdc++.h>
#include <climits>
using namespace std;


int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string c = "";
    while (n && m) {
        if (s[n - 1] == t[m - 1]) n--, m--, c = s[n] + c;
        else if (dp[n - 1][m] > dp[n][m - 1]) n--; 
        else m--;
    }
    cout << c << endl;

}