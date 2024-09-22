/**
 *    author:  compounding
 *    created: 2024-09-18 00:05:32
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

    vi v;
    int x = 1;
    int y = 2;
    int sum = 2;
    int temp = 0;
    while (temp <= 4000000)
    {
        temp = x + y;
        x = y;
        y = temp;
        if (temp % 2 == 0)
        {
            sum += temp;
        }
    }
    cout << sum << endl;
    return 0;
}