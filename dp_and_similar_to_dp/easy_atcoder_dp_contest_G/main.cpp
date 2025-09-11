//topological sort
#include <bits/stdc++.h>

using namespace std;
const int MaxN = 1e5 + 5;
vector<int> adj[MaxN];
int indeg[MaxN] = {0}, dist[MaxN] = {0};
int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) if(!indeg[i]) q.push(i);
    while(q.size()) {
        int fr = q.front(); q.pop();
        for(int ne: adj[fr]) {
            indeg[ne]--;
            dist[ne] = max(dist[ne], dist[fr] + 1);
            if(!indeg[ne]) q.push(ne);
        }
    }
    // get maximum distance
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dist[i]);
    cout << ans;
}