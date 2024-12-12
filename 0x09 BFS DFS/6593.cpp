#include <bits/stdc++.h>
using namespace std;
char board[31][31][31];
int visited[31][31][31];
int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int L, R, C; cin >> L >> R >> C;
    while(!(L==0 && R==0 && C==0)){
        int sx=-1, sy=-1, sz=-1, ex=-1, ey=-1, ez=-1;
        queue<tuple<int,int,int>> Q;
        for(int i=0;i<L;i++){
            for(int j=0; j<R; j++) {
                for(int k=0; k<C; k++){
                    cin >> board[j][k][i];
                    if(board[j][k][i]=='S') {
                        sz=i; sy=k; sx=j;
                        Q.push({j,k,i});
                    }
                    if(board[j][k][i]=='E') {
                        ez=i; ey=k; ex=j;
                    }
                    visited[j][k][i]=0;
                }
            }
        }
        visited[sx][sy][sz] = 1;
        while(!Q.empty()){
            auto cur= Q.front(); Q.pop();
            for(int l=0;l<6;l++){
                int x= get<0>(cur)+dx[l];
                int y= get<1>(cur)+dy[l];
                int z= get<2>(cur)+dz[l];
                if(x>=R||y>=C||z>=L||x<0||y<0||z<0) continue;
                if(board[x][y][z] == '#') continue;
                if(visited[x][y][z] && visited[x][y][z] <= visited[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1) continue;
                visited[x][y][z] = visited[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
                Q.push({x,y,z});
                
            }
            
        }
        if(ex>=0 && ey>=0 && ez>=0 && visited[ex][ey][ez]) cout << "Escaped in " << visited[ex][ey][ez]-1 << " minute(s).\n";
        else cout << "Trapped!\n";
        
        cin >> L >> R >> C;
    }
}