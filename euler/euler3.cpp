/**
 *    author:  compounding
 *    created: 2024-09-18 00:13:51
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
// sieve of eratosthenes
vector<bool> isprime; // true=prime
void primecheck(int n)
{
    isprime.clear();
    isprime.assign(n + 1, true);
    isprime[0] = false;
    isprime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isprime[j] = false;
            }
        }
    }
}
signed main()
{
    NeedForSpeed;
    int n = 600851475143;
    int limit = sqrt(n);
    primecheck(limit);
    int largest = 2;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (isprime[i])
            {
                largest = max(largest, i);
            }
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1 && isprime[n])
    {
        largest = max(largest, n);
    }
    cout << largest << endl;
    return 0;
}