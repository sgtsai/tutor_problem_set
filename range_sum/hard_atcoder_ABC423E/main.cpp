#include <bits/stdc++.h>

using namespace std;
const int MaxN = 3e5 + 5;
long long pre1[MaxN], pre2[MaxN], pre3[MaxN], arr[MaxN];
int main() {
    int n, q;
    cin >> n >> q;
    pre1[0] = pre2[0] = pre3[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        pre1[i] = pre1[i-1] + arr[i];
        pre2[i] = pre2[i-1] + arr[i] * i;
        pre3[i] = pre3[i-1] + arr[i] * i * i;
    }
    while(q--) {
        long long L, R;
        cin >> L >> R;
        cout << -1 * (pre3[R] - pre3[L-1]) + (L+R) * (pre2[R] - pre2[L-1]) + (-L+1) * (R+1) * (pre1[R] - pre1[L-1]) << endl;
    }
}