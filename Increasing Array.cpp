#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long ans=0;
    for(int i=1;i<n;i++){
       if(arr[i]<arr[i-1]){
         ans+=(arr[i-1]-arr[i]);
         arr[i]=arr[i-1];
       }
    }
    cout<<ans<<'\n';
    return 0;
}