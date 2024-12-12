//grid = dfs 여러 시작; 전체 count
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int t; cin >> t;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    while(t--){
        int count = 0;
        int arr[51][51];
        int vis[51][51];
        for(int i=0;i<51;i++){
            for(int j=0;j<51;j++){
                arr[i][j]=0; vis[i][j]=0;
            }
        }
        
        queue<pair<int,int>> Q;
        int m,n,k; cin >> m >> n >> k;
        for(int i=0;i<k;i++){
            int x,y; cin >> x >> y;
            arr[x][y]=1;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!arr[i][j] || vis[i][j]) continue;
                Q.push({i,j});
                vis[i][j]=1;
                
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int l=0;l<4;l++){
                        int x = cur.first+dx[l];
                        int y= cur.second+dy[l];
                        if(x>=m||y>=n||x<0||y<0) continue;
                        if(vis[x][y]||!arr[x][y]) continue;
                        vis[x][y]=1;
                        Q.push({x,y});
                    }
                }
                count++;
            }
        }
        cout << count << '\n';
        
        
    }
}