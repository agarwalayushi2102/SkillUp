#include <bits/stdc++.h>
#include <climits>
using namespace std;


int main() {
    int n, mxWeight;
    cin >> n >> mxWeight;
    vector<long long int> wt(n);
    vector<long long int> val(n);
    
    for(int i = 0; i < n; i++) {
        long long int a, b;
        cin >> a >> b;
        wt[i] = a;
        val[i] = b;
        
    }

    vector<long long int> prev(mxWeight + 1, 0), curr(mxWeight + 1, 0);

    for (int i = 0; i <= mxWeight; i++) {
        prev[i] = ((int)(i / wt[0]) )* val[0];
    }

    for (int ind = 1; ind < n; ind++) {
        for(int j = 0; j <= mxWeight; j++) {
            long long int notTake = 0 + prev[j];
            long long int take = 0;
            if(wt[ind] <= j)
                take = val[ind] + prev[j-wt[ind]];
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }

    cout << prev[mxWeight];
    
}
