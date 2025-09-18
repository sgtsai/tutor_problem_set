#include <bits/stdc++.h>

using namespace std;
int dp[100005];
int arr[100005];
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        dp[1] = 0;
        for(int i = 2; i <= n/2 + (n%2); i++) {
            dp[i] = dp[i-1] + (arr[i] == arr[i-1]) + (arr[n-i+1] == arr[n-i+2]);
            dp[i] = min(dp[i], dp[i-1] + (arr[n-i+1] == arr[i-1]) + (arr[i] == arr[n-i+2]));
        }
        if(n % 2 == 0) {
            cout << dp[n/2] + (arr[n/2] == arr[n/2+1]) << endl;
        }
        else cout << dp[n/2+n%2] << endl;
    }
}