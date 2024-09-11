#include <bits/stdc++.h>
#include <climits>
using namespace std;


int main() {
    int n;
    int mxWeight;
    cin >> n >> mxWeight;
    vector<int> wt(n);
    vector<int> val(n);
    
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        wt[i] = a;
        val[i] = b;
        
    }

    vector<int> prev(mxWeight + 1, 0), curr(mxWeight + 1, 0);

    for (int i = 0; i <= mxWeight; i++) {
        prev[i] = ((int)(i / wt[0]) )* val[0];
    }

    for (int ind = 1; ind < n; ind++) {
        for(int j = 0; j <= mxWeight; j++) {
            int notTake = prev[j];
            int take = 0;
            if(wt[ind] <= j)
                take = 0LL + val[ind] + prev[j-wt[ind]];
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }

    cout << prev[mxWeight];
    
}