/**
 *    author:  compounding
 *    created: 2024-09-18 14:58:47
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
const int N = 2e5 + 1;
vi tree[N];
vvi dp(N, vi(2, 0));
void dfs(int node, int par)
{
    vi prefix, suffix;
    // make sure that dp arrays are 0
    dp[node][0] = 0;
    dp[node][1] = 0;
    bool leaf = true;
    for (auto child : tree[node])
    {
        if (child == par)
        {
            continue;
        }
        else
        {
            leaf = false; // means it not a leaf node
            dfs(child, node);
        }
    }
    if (leaf)
    {
        return; // as for them dp[node][1] & dp[child][0] will be 0
    }
    // calculate the prefix and suffix so that its easier to calculate dp[node][1]
    for (auto child : tree[node])
    {
        if (child == par)
        {
            continue;
        }
        else
        {
            prefix.push_back(max(dp[child][0], dp[child][1]));
            suffix.push_back(max(dp[child][0], dp[child][1]));
        }
    }
    for (int i = 1; i < prefix.size(); i++)
    {
        prefix[i] += prefix[i - 1];
    }
    for (int i = suffix.size() - 2; i >= 0; i--)
    {
        suffix[i] += suffix[i + 1];
    }
    dp[node][0] = suffix[0]; // as we are not taking this node
    int i = 0;
    for (auto child : tree[node])
    {
        if (child == par)
        {
            continue;
        }
        dp[node][1] = max(dp[node][1], 1 + (i > 0 ? prefix[i - 1] : 0) + dp[child][0] + ((i + 1) < suffix.size() ? suffix[i + 1] : 0));
        i++;
    }
}
signed main()
{
    NeedForSpeed;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, -1);
    // it's rooted at index
    cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}