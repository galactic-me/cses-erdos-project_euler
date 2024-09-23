/**
 *    author:  compounding
 *    created: 2024-09-24 02:32:25
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
    // Josephus Problem I, use queue for processing
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    bool flag = false;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        // if we dont remove it, add it to the back
        if (!flag)
        {
            q.push(x);
        }
        // else print it and change flag so that we dont remove the exact next element
        else
        {
            cout << x << " ";
        }
        flag = !flag;
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