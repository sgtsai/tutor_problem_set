#include <bits/stdc++.h>

using namespace std;
map<int, int> cnt;
priority_queue<pair<int,int>> pq; // {cnt[i], i}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cnt[num]++;
    }
    for(auto it = cnt.begin(); it != cnt.end(); it++)
        pq.push({it->second, it->first});
    //cout << "OK\n";
    vector<vector<int>> ans;
    while(pq.size() >= 3) {
        //cout << "enter\n";
        vector<pair<int,int>> buf;
        int arr[3];
        for(int i = 0; i < 3; i++) {
            //cout << "i: " << i << endl;
            auto to = pq.top(); pq.pop();
            arr[i] = to.second;
            if(to.first-1>0) buf.push_back({to.first-1, to.second});
            //cout << "i: " << i << endl;
        }
        //cout << "ok2\n";
        ans.push_back({arr[0], arr[1], arr[2]});
        //cout << "ok3\n";
        for(int i = 0; i < buf.size(); i++) pq.push(buf[i]);
        //cout << "ok4\n";
        //cout << "enter finished\n";
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        sort(ans[i].begin(), ans[i].end());
        cout << ans[i][2] << ' ' << ans[i][1] << ' ' << ans[i][0] << endl;
    }
}