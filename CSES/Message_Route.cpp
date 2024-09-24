#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; 
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> distance(n, -1);
    vector<int> parent(n, -1);
    queue<int> q;
    
    q.push(0);
    distance[0] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
    if (distance[n-1] == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << distance[n-1] + 1 << "\n";
        vector<int> path;
        for (int at = n - 1; at != -1; at = parent[at]) {
            path.push_back(at + 1);
        }
        reverse(path.begin(), path.end());
        for (int computer : path) {
            cout << computer << " ";
        }
        cout << "\n";
    }

    return 0;
}
