#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> weights(n);
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    int i = 0, j = n - 1;
    int gondolas = 0;
    while (i <= j) {
        if (weights[i] + weights[j] <= x) {
            i++;
            j--;
        } else {
            j--;
        }
        gondolas++;
    }
    cout << gondolas << endl;
    return 0;
}