#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt25 = n, cnt21 = n, cnt18 = n;
    int ans = 0;
    while(cnt25 >= 2) {
        cnt25 -= 2;
        ans++;
    }
    if(cnt25 == 1) {
        ans++;
        cnt25 = 0;
        cnt21--;
    }
    while(cnt21 >= 2) {
        cnt21 -= 2;
        cnt18--;
        ans++;
    }
    if(cnt21 == 1) {
        cnt21--;
        cnt18 -= 2;
        ans++;
    }
    while(cnt18 > 0) {
        cnt18 -= 3;
        ans++;
    }
    cout << ans;

}