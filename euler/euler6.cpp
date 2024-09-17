/**
 *    author:  compounding
 *    created: 2024-09-18 00:10:41
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
    int sum1, sum2;
    int n = 100;
    sum1 = n * (n + 1) * (2 * n + 1) / 6;
    sum2 = (n * (n + 1) / 2) * (n * (n + 1) / 2);
    cout << sum2 - sum1 << endl;
    return 0;
}