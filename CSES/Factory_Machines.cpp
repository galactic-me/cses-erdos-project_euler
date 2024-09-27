    #include <bits/stdc++.h>
    using namespace std; 
    typedef long long ll;
    ll products(vector<ll>&v,ll T){
        ll ans=0;
        for(auto it:v){
            ans+=T/it;
        }
        return ans;
    }
    int main(){
        ll n,t;
        cin>>n>>t;
        vector<ll>v(n);
        for(ll i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        ll lo=1;
        ll hi=v[0]*t;
         while(lo<hi){
            ll mid=(lo+hi)/2;
            ll numbo=products(v,mid);
            if(numbo<t){
                lo=mid+1;
            }
            else if(numbo>=t){
                hi=mid;
            }
        }
        cout<<lo;
        return 0;
    }