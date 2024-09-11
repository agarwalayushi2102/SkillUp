
#include <bits/stdc++.h>
#include <climits>
using namespace std;

void solve(){
int n ;
cin >> n;
 vector<int> h(n);
 for(int i = 0; i < n; i++) cin >> h[i];

vector<int> dp(n , INT_MAX);

dp[0]=0;
dp[1]= abs(h[1]-h[0]);
for(int i=2; i<n ; i++){
int dif_1 = abs(h[i]-h[i-1]);
int dif_2 = abs(h[i]-h[i-2]);

dp[i]= min(dp[i-1]+dif_1 , dp[i-2]+dif_2);

}

cout<<dp[n-1];


}



int main() {
	solve();
}

