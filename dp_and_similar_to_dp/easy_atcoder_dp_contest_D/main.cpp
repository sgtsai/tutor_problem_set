#include <bits/stdc++.h>

using namespace std;
long long dp[100005] = {0};
int main() {
    int n, w;
    cin >> n >> w;
    for(int i = 0; i < n; i++) {
        int num, val;
        cin >> num >> val;
        for(int i = w; i - num >= 0; i--) {
            dp[i] = max(dp[i], dp[i-num] + val);
        }
    }
    cout << dp[w];
}