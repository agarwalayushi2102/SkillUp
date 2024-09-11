#include <bits/stdc++.h>
#include <climits>
using namespace std;


int vacation(int n , vector<vector<int> > act) {
    vector<vector<int> > dp(n, vector<int>(3, 0));
    dp[0][0] = act[0][0];
    dp[0][1] = act[0][1];
    dp[0][2] = act[0][2];

    for( int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + act[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + act[i][1];
        dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + act[i][2];   
    }
    int result = max(dp[n-1][0], dp[n-1][1]);
    result = max(result, dp[n-1][2]);
    return result;
    
}


int main() {
    int n;
    cin >> n;
    vector<vector<int> > act;
    for(int i = 0; i < n; i++) {
        vector<int> a;
        for(int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        act.push_back(a);
    }

    int happiness = vacation(n, act);
    cout << happiness;
}