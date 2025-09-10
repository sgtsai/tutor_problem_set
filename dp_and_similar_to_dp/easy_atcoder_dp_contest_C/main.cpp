#include <bits/stdc++.h>

using namespace std;
const int MaxN = 1e5 + 5;
int arr[MaxN][3];
int dp[MaxN][3];
int main() {
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + arr[i][1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }
    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]);
}   