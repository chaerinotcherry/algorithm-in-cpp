#include <bits/stdc++.h>
using namespace std;
int main(){
    //cin.tie(0); ios::sync_with_stdio(0);
    queue<pair<int,int>> Q;
    int board[1001][1001];
    int visited[1001][1001]; // ripened 여부
    int n, m;
    int count=0;
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            visited[i][j]=0;
            if(board[i][j]==1 || board[i][j]==0) count++;
        }
    }
    int total = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]!=1) continue;
            visited[i][j] =1;
            Q.push({i,j});
            total++;
            if(total==count) {
                cout << 0;
                return 0;
            }
        }
    }
    Q.push({-1,-1});
    int period =1;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur.first==-1 && cur.second==-1) {
            period++;
            if(!Q.empty()) {
                Q.push({-1,-1});
            }
            continue;
        }
        for(int i=0;i<4;i++){
            int x = cur.first+dx[i];
            int y = cur.second+dy[i];
            if(x>=n||y>=m||x<0||y<0) continue;
            if(visited[x][y]==1||board[x][y]==-1) continue;
            visited[x][y]=1;
            total++;
            if(total==count) {
                cout << period;
                return 0;
            }
            Q.push({x,y});
        }
    }
    cout << -1;
    
    
}