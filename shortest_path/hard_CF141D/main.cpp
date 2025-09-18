//dijsktra
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
map<int, vector<pii>> adj;
map<int, int> dist, from;
vector<int> points, ans;
map<pii, pii> get_id_set;

int get_id(int n1, int n2) {
    if(n1 > n2) swap(n1, n2);
    return get_id_set[{n1,n2}].first;
}

int main() {
    int n, L;
    cin >> n >> L;
    points.push_back(0);
    points.push_back(L);
    for(int i = 1; i <= n; i++) {
        int x, d, t, p;
        cin >> x >> d >> t >> p;
        if(x - p >= 0) {
            adj[x - p].push_back({x + d, p + t});
            points.push_back(x - p);
            points.push_back(x + d);
            if(!get_id_set.count({x-p,x+d}) || p + t < get_id_set[{x-p,x+d}].second)
                get_id_set[{x - p, x + d}] = {i, p+t};
        }
    }
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    for(int i = 0; i < points.size(); i++) {
        if(i) adj[points[i]].push_back({points[i-1], points[i]-points[i-1]});
        if(i != points.size()-1) adj[points[i]].push_back({points[i+1], points[i+1]-points[i]});
    }
    dist[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; //{dist, idx}
    pq.push({0,0});
    while(pq.size()) {
        auto fr = pq.top(); pq.pop();
        //cout << "fr_idx: " << fr.second << endl;
        if(!adj.count(fr.second)) continue;
        if(fr.second == L) {
            break;
        }
        for(auto ne: adj[fr.second]) {
            if(adj.count(ne.first)) {
                if(!dist.count(ne.first) || dist[ne.first] > dist[fr.second] + ne.second) {
                    from[ne.first] = fr.second;
                    dist[ne.first] = dist[fr.second] + ne.second;
                }
                pq.push({dist[ne.first], ne.first});
            }
        }
        adj.erase(fr.second);
    }
    cout << dist[L] << endl;
    int now = L;
    while(now) {
        //cout << "now: " << now << endl;
        //cout << "from: " << from[now] << endl;
        if(abs(from[now] - now) != abs(dist[from[now]] - dist[now])) ans.push_back(get_id(now, from[now]));
        now = from[now];
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(int i: ans) {
        cout << i << ' ';
    }
}