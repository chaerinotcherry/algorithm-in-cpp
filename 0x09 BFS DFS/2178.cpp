#include <bits/stdc++.h>
using namespace std;
#define MIN(x,y) (x>y)?(y):(x);
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int board[101][101];
    int visited[101][101];
    queue<pair<int,int>> Q;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int n, m; cin >> n >> m;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<m;j++){
            board[i][j]=str[j]-'0';
            visited[i][j] = 0;
        }
    }
    
    visited[0][0] = 1;
    Q.push({0,0});
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i=0;i<4;i++){
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if(x>=n || y>=m || x<0 || y<0) continue;
            if(board[x][y]==0) continue;
            if(visited[x][y]!=0 && visited[x][y] <= visited[cur.first][cur.second]+1) continue;
            visited[x][y] = visited[cur.first][cur.second] + 1;
            Q.push({x,y});
        }
    }
    
    cout << visited[n-1][m-1];
    
}