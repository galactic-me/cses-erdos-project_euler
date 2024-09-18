/**
 *    author:  compounding
 *    created: 2024-09-13 21:17:02
 **/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define NeedForSpeed                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vpi;
#define f first
#define s second
#define endl "\n"
const int mod = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int maxdistance = 0;
int bfs(int node, vvi &adj, int &ans)
{
    queue<int> q;
    q.push(node);
    vi dist(adj.size(), -1);
    dist[node] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > maxdistance)
                {
                    maxdistance = dist[v];
                    ans = v;
                }
            }
        }
    }
    return ans;
}
signed main()
{
    NeedForSpeed;
    int n;
    cin >> n;
    vvi adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    bfs(1, adj, ans);
    bfs(ans, adj, ans);
    cout << maxdistance << endl;
    return 0;
}