    #include <bits/stdc++.h>
    using namespace std; 
    typedef long long ll;
    int main(){
            int n;
            cin>>n;
            vector<int>v(n);
            for(int i=0;i<n;i++){
                cin>>v[i];
            }
            set<int>s(v.begin(),v.end());
            cout<<s.size();
        return 0;
    }