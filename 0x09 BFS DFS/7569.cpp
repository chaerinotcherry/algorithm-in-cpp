#include <bits/stdc++.h>
using namespace std;
//여러 시작점
int tom[101][101][101];
long visited[101][101][101]; // 최소 시간 담당
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int m,n,h; cin >> n >> m >> h;
    long zero = 0; 
    queue<tuple<int,int,int>> Q;
    for(int k=0;k<h;k++){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> tom[i][j][k];
                visited[i][j][k]=0;
                if(tom[i][j][k]==0) zero++;
                if(tom[i][j][k]==1) {
                    visited[i][j][k]=1;
                    Q.push({i,j,k});
                }
            }
        }
    }
    if(!zero) {
        cout << 0;
        return 0;
    }
    long max = 0;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i=0;i<6;i++){
            int x = get<0>(cur) + dx[i];
            int y= get<1>(cur) + dy[i];
            int z = get<2>(cur) + dz[i];
            if(x>=m||y>=n||z>=h||x<0||y<0||z<0) continue;
            if(tom[x][y][z]==-1) continue;
            if(visited[x][y][z] && visited[x][y][z] <= visited[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1) continue;
            visited[x][y][z] = visited[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            Q.push({x,y,z});
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<h;k++){
                if(tom[i][j][k]!=-1 && !visited[i][j][k]){
                    cout << -1;
                    return 0;
                }
                if(visited[i][j][k]>=max) max=visited[i][j][k];
            }
        }
    }
    cout << max-1;
}