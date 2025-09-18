#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int onecnt = 0, twocnt = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if(num == 1) onecnt++;
            if(num == 2) {
                twocnt = 1LL * (onecnt + twocnt + twocnt) % 998244353;
            }
            if(num == 3) ans = (ans + twocnt) % 998244353;
        }
        cout << ans << endl;
    }
}