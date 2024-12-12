//개수 근데 2종류만 하면 됨
#include <bits/stdc++.h>
using namespace std;
int main(){
    char board[101][101];
    int visited[101][101];
    int visited2[101][101];
    int n; cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            visited[i][j]=0;
            visited2[i][j]=0;
        }
    }
    int dx[4] = {0,1,-1,0};
    int dy[4] = {1,0,0,-1};
    int blind = 0, norm = 0;
    queue<pair<int,int>> Q;
    queue<pair<int,int>> Q2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]) continue;
            visited[i][j]=1;
            Q.push({i,j});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                char color = board[cur.first][cur.second];
                for(int i=0;i<4;i++){
                    int x = cur.first + dx[i];
                    int y = cur.second + dy[i];
                    if(x>=n||y>=n||x<0||y<0) continue;
                    if(visited[x][y] || color!=board[x][y]) continue;
                    visited[x][y]=1;
                    Q.push({x,y});
                }
            }
            norm++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited2[i][j]) continue;
            visited2[i][j]=1;
            Q2.push({i,j});
            while(!Q2.empty()){
                auto cur = Q2.front(); Q2.pop();
                char color = board[cur.first][cur.second];
                for(int i=0;i<4;i++){
                    int x = cur.first + dx[i];
                    int y = cur.second + dy[i];
                    if(x>=n||y>=n||x<0||y<0) continue;
                    if(visited2[x][y]) continue;
                    if(!((color=='G' || color=='R') && (board[x][y]=='G' || board[x][y]=='R') || color==board[x][y])) continue;
                    visited2[x][y]=1;
                    Q2.push({x,y});
                }
            }
            blind++;
        }
    }
    cout << norm << ' ' << blind;
    
}