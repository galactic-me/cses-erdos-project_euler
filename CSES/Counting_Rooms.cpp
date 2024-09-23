    #include <bits/stdc++.h>
    using namespace std; 
    typedef long long ll;
    void solve(vector<vector<char>>&map,vector<vector<int>>&vis,int n, int m,int row,int col, int dx[], int dy[]){
        vis[row][col]=1;
        //cout << "Visiting cell (" << row << ", " << col << ")\n";debug
        for(int i=0;i<4;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && map[nrow][ncol]=='.' && !vis[nrow][ncol]){
                //cout<<"nrow :"<<nrow<<" ncol;"<<ncol<<"\n"; debug
                solve(map,vis,n,m,nrow,ncol,dx,dy);

            }
        }
    }
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
            ll n,m;
            cin>>n>>m;
            vector<vector<char>>map(n,vector<char>(m));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cin>>map[i][j];
                }
            }
            vector<vector<int>>vis(n,vector<int>(m,0));
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            int cnt=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(map[i][j]=='.' && !vis[i][j]){
                        //cout<<i<<" "<<j<<'\n';debug
                        solve(map,vis,n,m,i,j,dx,dy);
                        cnt++;
                    }
                }
            }
            cout<<cnt;
        return 0;
    }