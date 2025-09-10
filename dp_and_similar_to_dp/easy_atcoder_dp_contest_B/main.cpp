#include <bits/stdc++.h>

using namespace std;
const int MaxN = 1e5 + 5;
int dp[MaxN], arr[MaxN];
int main() {
    int n, k;
    cin >> n >> k;
    fill(begin(dp), end(dp), 2e9);
    dp[1] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        for(int j = max(1, i-k); j < i; j++) {
            dp[i] = min(dp[i], dp[j] + abs(arr[i]-arr[j]));
        }
    }
    cout << dp[n];
}