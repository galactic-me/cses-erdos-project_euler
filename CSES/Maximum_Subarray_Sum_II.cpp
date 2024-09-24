/**
 *    author:  compounding
 *    created: 2024-09-24 23:15:07
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
    int n, a, b;
    cin >> n >> a >> b;
    // for range queries we have to use prefix sum too
    vi pfx(n + 1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pfx[i + 1] = pfx[i] + x;
    }
    multiset<int> m;
    int ans = LLONG_MIN;
    for (int i = a; i <= n; i++)
    { // if in multiset we only have values from [a,b],then pfx[i]-pfx[j] will be maximum
        // as i is fixed and j can move from [i-b, i-a], and multiset will have it min value on top
        if (i > b)
        {
            m.erase(m.find(pfx[i - b]));
        }
        m.insert(pfx[i - a]);
        ans = max(ans, pfx[i] - *m.begin());
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