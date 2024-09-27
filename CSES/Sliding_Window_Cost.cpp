/**
 *    author:  compounding
 *    created: 2024-09-24 19:21:56
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
int n, k;
multiset<int> low, high;
// extra addition to sliding window median problem
int lowsum, highsum;
vi v;
// insertion function
void insert(int x)
{
    if (!low.empty() && x > *low.rbegin())
    {
        high.insert(x);
        highsum += x;
        // check if high's size > (k / 2)
        if ((int)high.size() > (k / 2))
        {
            // remove the first element of high and insert it into low
            low.insert(*high.begin());
            lowsum += *high.begin();
            highsum -= *high.begin();
            high.erase(high.find(*high.begin()));
        }
    }
    else
    {
        low.insert(x);
        lowsum += x;
        if ((int)low.size() > (k + 1) / 2)
        {
            high.insert(*low.rbegin());
            highsum += *low.rbegin();
            lowsum -= *low.rbegin();
            low.erase(low.find(*low.rbegin()));
        }
    }
}

// deletion function
void delet(int x)
{
    if (high.find(x) != high.end())
    {
        highsum -= x;
        high.erase(high.find(x));
    }
    else
    {
        lowsum -= x;
        low.erase(low.find(x));
    }
    if ((int)low.size() < (int)high.size())
    {
        lowsum += *high.begin();
        highsum -= *high.begin();
        low.insert(*high.begin());
        high.erase(high.find(*high.begin()));
    }
}
void solve()
{
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < k; i++)
    {
        insert(v[i]);
    }
    // output of first window
    int median = *low.rbegin();
    int numlow = low.size();
    int numhigh = high.size();
    cout << (numlow * median - lowsum) + (highsum - numhigh * median) << " ";
    for (int i = k; i <= (n - 1); i++)
    {
        if (k == 1)
        {
            insert(v[i]);
            delet(v[i - k]);
        }
        else
        {
            delet(v[i - k]);
            insert(v[i]);
        }
        median = *low.rbegin();
        numlow = low.size();
        numhigh = high.size();
        cout << (numlow * median - lowsum) + (highsum - numhigh * median) << " ";
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