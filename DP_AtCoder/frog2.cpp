
#include <bits/stdc++.h>
#include <climits>
using namespace std;

void solve(){
int n ,k;
cin >> n >> k;
vector<int> h(n);
for(int i = 0; i < n; i++) cin >> h[i];

vector<int> dp(n , INT_MAX);

dp[0]=0;
dp[1] = abs(h[1]-h[0]);
for (int i = 2; i < n ; i++) {
    int min_diff = INT_MAX;
    for(int j = 1; i >= j && j <= k; j++) {
        int diff = abs(h[i] - h[i-j]);
        min_diff = min(min_diff, diff + dp[i-j]);
    }

    dp[i]= min_diff;
}

cout << dp[n-1];


}



int main() {
	solve();
}

