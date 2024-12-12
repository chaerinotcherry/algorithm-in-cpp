#include <bits/stdc++.h>
using namespace std;
#define MIN(x,y) (x>y) ? (y) : (x);
char board[1001][1001];
long visited[1001][1001][2];// x, y, broke
queue<tuple<int,int,int>> Q;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int main(){
    int n, m; cin >> m >> n;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            visited[i][j][0] = -1;
            visited[i][j][1] = -1;
        }
    }
    
    visited[0][0][0] = 1;
    Q.push({0,0,0});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(get<0>(cur)==m-1 && get<1>(cur)==n-1) {
            cout << visited[m-1][n-1][get<2>(cur)]; return 0;
        }
        for(int i=0;i<4;i++){
            
            int x = get<0>(cur) + dx[i];
            int y = get<1>(cur) + dy[i];
            int broke = get<2>(cur);
            if(x>=m || y>=n || x<0 || y<0) continue;
            if(visited[x][y][broke]>-1) continue;
            if(!broke && board[x][y]=='1') {
                broke = 1;
                visited[x][y][1] = visited[get<0>(cur)][get<1>(cur)][0]+1;
                Q.push({x,y,broke});
            }
            else if((broke && board[x][y]!='1') || (!broke && board[x][y]!='1')) {
                visited[x][y][broke] = visited[get<0>(cur)][get<1>(cur)][broke]+1;
                Q.push({x,y,broke});
            }
            
        }
    }
    cout << -1;
}