/**
 *    author:  compounding
 *    created: 2024-09-24 18:17:19
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
bool check(int mid, vi &a, int t)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        count += mid / a[i];
        // overflow avoid
        if (count >= t)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    int n, t;
    cin >> n >> t;
    vi a(n);
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mini = min(mini, a[i]);
    }
    int low = 0LL;
    int high = mini * t; // make all using the machine with smallest time
    // think in terms of if we fix the time, then we can calculate the number of products produced
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(mid, a, t))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
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