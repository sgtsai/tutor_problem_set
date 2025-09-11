#include <bits/stdc++.h>

using namespace std;
const int MaxN = 3005;
int dp[MaxN][MaxN];
string ans_str;
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    str1 = ' ' + str1;
    str2 = ' ' + str2;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i < str1.length(); i++) {
        for(int j = 1; j < str2.length(); j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(str1[i] == str2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;

    }
    //cout << "IIIIII\n";
    int nowi = str1.length()-1, nowj = str2.length()-1;
    while(dp[nowi][nowj] > 0) {
        if(str1[nowi] == str2[nowj]) {
            ans_str += str1[nowi];
            nowi--, nowj--;
        }
        else if(dp[nowi][nowj-1] >= dp[nowi-1][nowj])
            nowj--;
        else nowi--;

    }
    reverse(ans_str.begin(), ans_str.end());
    cout << ans_str;
}