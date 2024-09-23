#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, vector<int>& vis, int index) {
    vis[index] = 1;
    for (auto it : adj[index]) {
        if (!vis[it]) {
            dfs(adj, vis, it); 
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> road(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> road[i][0] >> road[i][1];
        road[i][0]--; 
        road[i][1]--;  
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        adj[road[i][0]].push_back(road[i][1]);
        adj[road[i][1]].push_back(road[i][0]);
    }
    vector<int> vis(n, 0); 
    int cnt = 0;
    vector<int>cities;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(adj, vis, i);
            cities.push_back(i);
            cnt++;
        }
    }
    //for(auto a:cities){
        //cout<<a<<" ";
    //}debug
    cout<<cnt-1<<'\n';
    for(int i=1;i<cities.size();i++){
        cout<<cities[i-1]+1<<" "<<cities[i]+1<<'\n';
    }
    return 0;
}
