#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,char>>customers;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        customers.push_back({x,'a'});
        customers.push_back({y,'d'});
    }
    sort(customers.begin(),customers.end());
    ll cnt=0;
    ll maxcnt=0;
    for(auto& i:customers){
        if(i.second=='a'){
            cnt++;
        }
        else {
            cnt--;
        }
        if(cnt>maxcnt){
            maxcnt=cnt;
        }
    }
    cout<<maxcnt;
    return 0;
}