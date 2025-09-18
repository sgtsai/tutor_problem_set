#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
const int MaxN = 1e5 + 5;
int dist[MaxN];
bool vis[MaxN];
vector<pii> adj[MaxN];
int main() {
    int n, m, s, L;
    cin >> n >> m >> s;
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin >> L;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    fill(begin(dist), end(dist), INT_MAX);
    dist[s] = 0;
    pq.push({0, s});
    int ans = 0;
    while(pq.size()) {
        int nowidx = pq.top().second; pq.pop();
        if(vis[nowidx]) continue;
        vis[nowidx] = true;
        if(dist[nowidx] == L) {
            ans++; continue;
        }
        for(auto ne: adj[nowidx]) {
            if(!vis[ne.first] && dist[ne.first] > dist[nowidx] + ne.second) {
                dist[ne.first] = dist[nowidx] + ne.second;
                if(dist[ne.first] <= L) pq.push({dist[ne.first], ne.first});
            }
        }
    }
    //cout << "ans: " << ans << endl;
    int add = 0;
    for(int i = 1; i <= n; i++) {
        for(auto ne: adj[i]) {
            int diff1 = L - dist[i];
            if(diff1 > 0 && ne.second > diff1 && dist[ne.first] + ne.second - diff1 > dist[i] + diff1) add++;
            int diff2 = L - dist[ne.first];
            if(diff2 > 0 && ne.second > diff2 && dist[i] + ne.second - diff2 >= dist[ne.first] + diff2) add++;
        }
    }
    cout << ans + add / 2;
}