#include <bits/stdc++.h>

using namespace std;
const int MaxN = 1e5 + 5;
int main() {
    int n;
    cin >> n;
    int p0 = 0, p1 = 0, p2 = 0, dp0, dp1, dp2;
    for(int i = 1; i <= n; i++) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        dp0 = max(p1, p2) + n1;
        dp1 = max(p0, p2) + n2;
        dp2 = max(p0, p1) + n3;
        p0 = dp0, p1 = dp1, p2 = dp2;
    }
    cout << max(max(dp0, dp1), dp2);
}   