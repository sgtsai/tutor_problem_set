#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll digit_len[16];
int get_sum(char ch) {
    int res = 0;
    for(char i = '1'; i < ch; i++) res += i - '0';
    return res;
}
int main() {
    digit_len[0] = 0;
    for(int i = 1; i < 16; i++) {
        digit_len[i] = digit_len[i-1] + 9 * pow(10, i-1) * i;
    }
    int t;
    cin >> t;
    while(t--) {
        ll num, k, rem, ans = 0;
        cin >> k;
        for(int i = 1; i < 16; i++) {
            if(k <= digit_len[i]) {
                num = pow(1LL * 10, i-1) - 1;
                k -= digit_len[i-1];
                num += k / i;
                rem = k % i;
                break;
            }
        }
        //cout << "num: " << num << endl; // ok
        string rem_str = to_string(num+1);
        for(int i = 0; i < rem; i++) ans += rem_str[i] - '0';
        //cout << "ans: " << ans << endl; // ok
        string num_str = to_string(num);
        ll befor = 0;
        for(int i = 0; i < num_str.length(); i++) {
            ans += befor * 45 * pow(10, num_str.length() - i - 1);
            ans += get_sum(num_str[i]) * pow(10, num_str.length() - i - 1);
            ans += (num_str[i] - '0') * (num % (ll)pow(10, num_str.length()-i-1) + 1);
            befor *= 10;
            befor += num_str[i] - '0';
            //cout << "befor: " << befor << endl;
        }
        cout << ans << endl;
    }
}