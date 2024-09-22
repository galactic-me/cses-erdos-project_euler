/**
 *    author:  compounding
 *    created: 2024-09-08 21:48:15
 **/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define NeedForSpeed                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
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
    int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}