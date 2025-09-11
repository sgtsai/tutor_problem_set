#include <bits/stdc++.h>

using namespace std;
int dp[100005];
int main() {
    int n, limw;
    cin >> n >> limw;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        int wei, val;
        cin >> wei >> val;
        for(int i = 100000; i - val >= 0; i--) {
            dp[i] = min(dp[i], dp[i-val] + wei);
        }
    }
    int ans = 0;
    for(int i = 0; i <= 100000; i++) {
        if(dp[i] <= limw) ans = i;
    }
    cout << ans;
}