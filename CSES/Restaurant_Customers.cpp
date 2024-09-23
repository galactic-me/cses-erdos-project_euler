/**
 *    author:  compounding
 *    created: 2024-09-23 00:22:21
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
    int n;
    cin >> n;
    vpi v;
    // classic line sweep
    while (n--)
    {
        int start, end;
        cin >> start >> end;
        v.push_back({start, 1});
        v.push_back({end + 1, -1});
    }
    sort(all(v));
    int ans = 0, curr = 0;
    for (auto i : v)
    {
        curr += i.s;
        ans = max(ans, curr);
    }
    cout << ans << endl;
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