#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
const int MaxN = 1005;
vector<pii> edges;
int n, m, L, s, t;
vector<pil> adj[MaxN];
ll dist[MaxN];
int road[MaxN][MaxN];
bool vis[MaxN];
int from[MaxN];
vector<pii> minpath;
void back_track(int x) {
    while(x != s) {
        //cout << "x: " << x << endl;
        minpath.push_back({min(x, from[x]), max(x, from[x])});
        x = from[x];
    }
    if(dist[t] > L) {
        std::cout << "NO\n";
        return;
    }
    bool OK = false;
    for(auto nowedge : minpath) {
        if(road[nowedge.first][nowedge.second] == INT_MAX) {
            road[nowedge.first][nowedge.second] = L - dist[t] + 1;
            OK = true;
            break;
        }
    }
    if(!OK && dist[t] < L) {
        std::cout << "NO\n";
        return;
    }
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    fill(begin(dist), end(dist), 1e18);
    fill(begin(vis), end(vis), false);
    dist[s] = 0;
    pq.push({0, s});
    while(pq.size()) {
        int nowidx = pq.top().second; pq.pop();
        if(vis[nowidx]) continue;
        vis[nowidx] = true;
        if(nowidx == t) {
            if(dist[t] != L) {
                back_track(t);
                //cout << "dist: " << dist[t];
                return;
            }
            else break;
        }
        for(auto ne : adj[nowidx]) {
            int nowdis = road[nowidx][ne.first];
            if(nowdis == INT_MAX) nowdis = 1;
            if(dist[ne.first] > dist[nowidx] + nowdis) {
                dist[ne.first] = dist[nowidx] + nowdis;
                from[ne.first] = nowidx;
                pq.push({dist[ne.first], ne.first});
            }
        }
    }
    std::cout << "YES\n";
    for(auto nowedge : minpath) {
        if(road[nowedge.first][nowedge.second] == INT_MAX) {
            road[nowedge.first][nowedge.second] = road[nowedge.second][nowedge.first] = 1;
        }
    }
    for(auto ver: edges) {
        std::cout << ver.first << ' ' << ver.second << ' ' << road[ver.first][ver.second] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> L >> s >> t;
    fill(begin(dist), end(dist), 1e18);
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        if(w == 0) w = INT_MAX;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        road[u][v] = road[v][u] = w;
        edges.push_back({u,v});
    }
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while(pq.size()) {
        int nowidx = pq.top().second; pq.pop();
        if(vis[nowidx]) continue;
        vis[nowidx] = true;
        if(nowidx == t) {
            //cout << "mi dist: " << dist[t] << endl;
            //cout << "back_track\n";
            back_track(t);
            return 0;
        }
        for(auto ne : adj[nowidx]) {
            int nowdis = ne.second;
            if(ne.second == INT_MAX) nowdis = 1;
            if(dist[ne.first] > dist[nowidx] + nowdis) {
                dist[ne.first] = dist[nowidx] + nowdis;
                from[ne.first] = nowidx;
                pq.push({dist[ne.first], ne.first});
            }
        }
    }
    std::cout << "NO";
    return 0;
}