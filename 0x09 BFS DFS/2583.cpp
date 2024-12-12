#include <bits/stdc++.h>
using namespace std;
int board[101][101];
int visited[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int,int>> Q;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int m,n,k; cin >> m >> n >> k;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            board[i][j]=0; visited[i][j]=0;
        }
    }
    for(int i=0;i<k;i++){
        int lx,ly,rx,ry; cin >> lx >> ly >> rx >> ry;
        // lx ly (0,2) -> (3,0) (m-ly, lx)
        // rx ly (4,4) -> (1,4) (m-ry,rx)
        for(int j=m-ry;j<m-ly;j++){
            for(int k=lx;k<rx;k++){
                board[j][k]++;
            }
        }
    }
    int count = 0;
    vector<int> areas;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!board[i][j] && !visited[i][j]) {
                visited[i][j]=1;
                Q.push({i,j});
                int area = 1;
                count++;
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int i=0;i<4;i++){
                        int x = cur.first+dx[i];
                        int y = cur.second+dy[i];
                        if(x>=m||y>=n||x<0||y<0) continue;
                        if(board[x][y]!=0 || visited[x][y]) continue;
                        area++;
                        visited[x][y] = 1;
                        Q.push({x,y});
                        
                    }
                }
                areas.push_back(area);
            }
        }
    }
    cout << count << '\n';
    sort(areas.begin(),areas.end());
    for(auto a:areas) cout << a << ' ';
}