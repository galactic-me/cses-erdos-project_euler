/**
 *    author:  compounding
 *    created: 2024-09-24 18:38:35
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
    vpi v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].f >> v[i].s;
        sum += v[i].s;
    }
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        sum -= v[i].f * (n - i);
    }
    cout << sum << endl;
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