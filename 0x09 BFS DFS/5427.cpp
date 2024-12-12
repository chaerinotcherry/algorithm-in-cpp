#include <bits/stdc++.h>
using namespace std;
int fire[1001][1001];
int person[1001][1001];
char board[1001][1001]; // 메인 안에 선언하니깐 seg ER 남
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int min =1000001;
        queue<pair<int,int>> Q;
        queue<pair<int,int>> F;
        int r,c; cin >> c >> r;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin >> board[i][j];
                if(board[i][j]=='@') {
                    person[i][j]=1;
                    Q.push({i,j});
                    if(i==0 || j==0 || i==r-1 || j==c-1){
                        if(min>person[i][j]) min = person[i][j];
                    }
                } else person[i][j]=0;
                if(board[i][j]=='*'){
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
                // 0 아니면 반응 안하도록 해야함
                person[x][y] = person[cur.first][cur.second]+1;
                Q.push({x,y});
                if(x==0 || y==0 || x==r-1 || y==c-1){
                    if(min>person[x][y]) min = person[x][y];
                }
            }
        }
        
        if(min!=1000001) cout << min << '\n';
        else cout << "IMPOSSIBLE" << '\n';
    }
    
}