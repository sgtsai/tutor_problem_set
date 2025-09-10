#include <bits/stdc++.h>

using namespace std;
int dp[100005], h[100005];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        dp[i] = INT_MAX;
        if(i == 1) dp[1] = 0;
        if(i > 1) dp[i] = dp[i-1] + abs(h[i-1] - h[i]);
        if(i > 2) dp[i] = min(dp[i], dp[i-2] + abs(h[i-2]-h[i]));
    }
    cout << dp[n];
}