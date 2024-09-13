/**
 *    author:  compounding
 *    created: 2024-09-13 20:50:46
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
signed main()
{
    NeedForSpeed;
    int n;
    cin >> n;
    vi ans(n + 1);
    vi par(n + 1);
    par[0] = -1;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        par[i] = x;
        int k = i;
        while (par[k] != -1)
        {
            ans[par[k]]++;
            k = par[k];
        }
        if (par[k] == -1)
        {
            ans[par[k]]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}