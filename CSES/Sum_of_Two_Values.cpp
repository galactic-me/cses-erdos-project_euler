    #include <bits/stdc++.h>
    using namespace std; 
    typedef long long ll;
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
            int n,k;
            cin>>n>>k;
            vector<int>numbers(n);
            map<int,int>mp;
            bool check=false;
            for(int i=0;i<n;i++){
                cin>>numbers[i];
                int complement=k-numbers[i];
                if(mp.find(complement)!=mp.end() && mp[complement]!=i){
                    cout<<mp[complement]+1<<" "<<i+1;
                    check=true;
                    break;
                }
                mp[numbers[i]]=i;
            }
            if(!check){
                cout<<"IMPOSSIBLE";
            }
        return 0;
    }