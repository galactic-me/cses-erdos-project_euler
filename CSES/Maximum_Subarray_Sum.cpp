#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll currsum=a[0];
    ll maxsum=a[0];
    for(ll i=1;i<n;i++){
        currsum=max(a[i],currsum+a[i]);
        maxsum=max(currsum,maxsum);
    }
    cout<<maxsum;
    return 0;
}