    #include <bits/stdc++.h>
    using namespace std; 
    int products(vector<int>&v,int T){
        int ans=0;
        for(auto it:v){
            ans+=T/it;
        }
        return ans;
    }
    int main(){
        int n,t;
        cin>>n>>t;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int lo=1;
        int hi=v[0]*t;
         while(lo<hi){
            int mid=(lo+hi)/2;
            int numbo=products(v,mid);
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