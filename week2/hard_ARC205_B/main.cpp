#include <bits/stdc++.h>

using namespace std;
const int MaxN = 2e5 + 5;
int deg[MaxN] = {0};
int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += n-1 - (n-1-deg[i]) % 2;
    }
    cout << ans / 2;
}