#include <bits/stdc++.h>
using namespace std;
int fire[1001][1001];
int person[1001][1001];
char board[1001][1001];
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int min =1001;
    queue<pair<int,int>> Q;
    queue<pair<int,int>> F;
    int r,c; cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> board[i][j];
            if(board[i][j]=='J') {
                person[i][j]=1;
                Q.push({i,j});
                if(i==0 || j==0 || i==r-1 || j==c-1){
                    if(min>person[i][j]) min = person[i][j];
                }
            } else person[i][j]=0;
            if(board[i][j]=='F'){
                fire[i][j]=1;
                F.push({i,j});
            } else fire[i][j]=0;
        }
    }
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    while(!F.empty()){
        auto cur = F.front(); F.pop();
        for(int i=0;i<4;i++){
            int x = cur.first+dx[i];
            int y = cur.second+dy[i];
            if(x>=r||y>=c||x<0||y<0) continue;
            if(board[x][y]=='#') continue;
            if(fire[x][y] && fire[x][y]<=fire[cur.first][cur.second]+1) continue;
            fire[x][y] = fire[cur.first][cur.second]+1;
            F.push({x,y});
        }
    }
    
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i=0;i<4;i++){
            int x = cur.first+dx[i];
            int y = cur.second+dy[i];
            if(x>=r||y>=c||x<0||y<0) continue;
            if(board[x][y]=='#') continue;
            if(fire[x][y] && (fire[x][y] <= person[cur.first][cur.second]+1)) continue;
            if(person[x][y]!=0 && person[x][y]<= person[cur.first][cur.second]+1) continue;
            person[x][y] = person[cur.first][cur.second]+1;
            Q.push({x,y});
            if(x==0 || y==0 || x==r-1 || y==c-1){
                if(min>person[x][y]) min = person[x][y];
            }
        }
    }
    
    if(min!=1001) cout << min;
    else cout << "IMPOSSIBLE";
}