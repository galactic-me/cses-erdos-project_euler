/**
 *    author:  compounding
 *    created: 2024-09-13 21:09:15
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
const int maxn = 2e5 + 5;
vi adj[maxn];
int sub[maxn];
void dfs(int v)
{
    for (int child : adj[v])
    {
        dfs(child);
        // as its being calculated from below so we add child +1
        sub[v] += sub[child] + 1;
    }
}
signed main()
{
    NeedForSpeed;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << sub[i] << " ";
    }
    return 0;
}