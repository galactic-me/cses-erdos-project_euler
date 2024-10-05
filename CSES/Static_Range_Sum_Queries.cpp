#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
      int n,k;
      cin>>n>>k;
      vector<ll>v(n+1,0);
      for(ll i=1;i<=n;i++){
        cin>>v[i];
      }      
      vector<ll>pref(n+1,0);
      for(ll i=1;i<=n;i++){
        pref[i]=pref[i-1]+v[i];
      }
      while(k--){
        ll a,b;
        cin>>a>>b;
        cout<<pref[b]-pref[a-1]<<'\n';
      }
    return 0;
}