    #include <bits/stdc++.h>
    using namespace std; 
    typedef long long ll;
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
            int n,m;
            cin>>n>>m;
            vector<vector<char>>map(n,vector<char>(m));
            int srow,scol,lrow,lcol;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cin>>map[i][j];
                    if(map[i][j]=='A'){
                        srow=i;
                        scol=j;
                    }
                    if(map[i][j]=='B'){
                        lrow=i;
                        lcol=j;
                    }
                }
            }
            vector<vector<int>>vis(n,vector<int>(m,0));
            int dx[4]={-1,0,1,0};
            int dy[4]={0,1,0,-1};
            char there[4]={'U','R','D','L'};
            vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m));
            vector<vector<int>>parentdir(n,vector<int>(m,-1));
            queue<pair<int,int>>q;
            q.push({srow,scol});
            vis[srow][scol]=1;
            bool found=false;
            while(!q.empty()){
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                if(x==lrow && y==lcol){
                    found=true;
                    break;
                }
                for(int i=0;i<4;i++){
                    int nrow=x+dx[i];
                    int ncol=y+dy[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && (map[nrow][ncol]=='.' || map[nrow][ncol]=='B') && !vis[nrow][ncol]){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                        parent[nrow][ncol]={x,y};
                        parentdir[nrow][ncol]=i;
                    }
                }
            }
            if(found){
                cout<<"YES\n";
                string path;
                int x=lrow, y=lcol;
                while(x!=srow || y!=scol){
                   int prevdir=parentdir[x][y];
                   path.push_back(there[prevdir]);
                   int prevx=parent[x][y].first;
                   int prevy=parent[x][y].second;
                   x=prevx;
                   y=prevy;
                }
                reverse(path.begin(),path.end());
                cout<<path.size()<<'\n';
                cout<<path;
            }
            else{
                cout<<"NO\n";
            }
        return 0;
    }