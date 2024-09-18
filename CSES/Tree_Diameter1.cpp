/**
 *    author:  compounding
 *    created: 2024-09-18 15:19:03
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
const int N = (int)(2e5) + 1;
vi adj[N];
vi depth(N, 0);
vi ans(N, 0);
int maxi = 0;
void dfs(int src, int par)
{
    bool leaf = true;
    for (auto child : adj[src])
    {
        if (child == par)
        {
            continue;
        }
        leaf = false;
        dfs(child, src);
    }
    if (leaf)
    {
        return;
    }
    vi temp;
    depth[src] = 0;
    for (auto child : adj[src])
    {
        if (child == par)
        {
            continue;
        }
        temp.push_back(depth[child]);
    }
    sort(temp.rbegin(), temp.rend());
    depth[src] = temp[0] + 1;
    if (temp.size() >= 2)
    {
        ans[src] = temp[0] + temp[1] + 2;
        maxi = max(maxi, ans[src]);
    }
    else
    {
        ans[src] = depth[src];
        maxi = max(maxi, ans[src]);
    }
}

signed main()
{
    NeedForSpeed;
    int n = 1;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1);
    cout << maxi << endl;
    return 0;
}
