/**
 *    author:  compounding
 *    created: 2024-09-21 02:03:22
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
    vi a(n);
    vi modulo(n, 0);
    int prefsum = 0;
    int cnt = 0;
    modulo[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prefsum += a[i];
        int rem = prefsum % n;
        if (rem < 0)
        {
            rem += n;
        }
        cnt += modulo[rem];
        modulo[rem]++;
    }
    cout << cnt << endl;
    return 0;
}