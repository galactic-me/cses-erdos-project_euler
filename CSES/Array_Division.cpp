#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
int subarraycount(ll num,vector<ll>&a){
    ll sum=0;
    ll count=1;
    for(ll i=0;i<a.size();i++){
        if(a[i]>num)return INT_MAX;
        if(sum+a[i]>num){
            count++;
            sum=a[i];
        }
        else{
            sum+=a[i];
        }
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll lo=*max_element(a.begin(),a.end());
    ll hi=accumulate(a.begin(),a.end(),0LL);
    while(lo<hi){
        ll mid=(hi+lo)/2;
        ll numberofsubarrays=subarraycount(mid,a);
        if(numberofsubarrays>k){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    cout<<lo;
    return 0;
}