#include <bits/stdc++.h>

using namespace std;
const int MaxN = 1005, mod = 1e9 + 7;
char arr[MaxN][MaxN];
int dp[MaxN][MaxN];
int main() {
    int H, W;
    memset(dp, 0, sizeof(dp));
    cin >> H >> W;
    for(int i = 0; i <= H; i++)
        for(int j = 0; j <= W; j++) arr[i][j] = '#';
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            if(arr[i][j] == '#') continue;
            if(i == 1 && j == 1) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }   
        }
    }
    cout << dp[H][W];
}