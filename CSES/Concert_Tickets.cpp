/**
 *    author:  compounding
 *    created: 2024-09-23 00:17:42
 **/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define NeedForSpeed                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vpi;
#define f first
#define s second
#define endl "\n"
const int mod = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tickets.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        auto it = tickets.upper_bound(x);
        // assign the maximum closest to x (hence upper bound is needed)
        if (it == tickets.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            it--;
            cout << *it << endl;
            tickets.erase(it);
        }
    }
    return;
}

signed main()
{
    NeedForSpeed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}