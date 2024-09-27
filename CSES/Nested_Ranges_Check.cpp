/**
 *    author:  compounding
 *    created: 2024-09-24 15:45:24
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
struct range
{
    int l, r, in;
};

void solve()
{
    int n;
    cin >> n;
    // custom data structure to store the ranges
    vector<range> input(n);
    // so that while sorting the indexes dont get mixed up
    for (int i = 0; i < n; i++)
    {
        cin >> input[i].l >> input[i].r;
        input[i].in = i;
    }
    // sorting the ranges based on left point minimum first, and right point maximum first
    sort(all(input), [&](range a, range b)
         {
        if (a.l == b.l)
        {
            return a.r > b.r;
        }
        return a.l < b.l; });
    vi contains(n, 0), contained(n, 0);
    // contains
    int minimumr = INT_MAX; // maxmimum r
    for (int i = (n - 1); i >= 0; i--)
    {
        if (input[i].r >= minimumr)
        {
            contains[input[i].in] = 1;
        }
        minimumr = min(minimumr, input[i].r);
    }
    // contained
    int maxir = 0; // minimum r
    for (int i = 0; i <= (n - 1); i++)
    {
        if (input[i].r <= maxir)
        {
            contained[input[i].in] = 1;
        }
        maxir = max(maxir, input[i].r);
    }
    for (int i = 0; i < n; i++)
    {
        cout << contains[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << contained[i] << " ";
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