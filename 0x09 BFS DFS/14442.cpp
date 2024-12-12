#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int visited[1001][1001][12];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            for(int l=0;l<m;l++){
                visited[j][l][i] = -1;
            }
        }
    }
    for(int j=0;j<n;j++){
        for(int l=0;l<m;l++){
            char a; cin >> a;
            arr[j][l] = a-'0';
        }
    }
    queue<tuple<int,int,int>> Q;
    Q.push({0,0,0});
    visited[0][0][0] = 1;
    int r;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        int x = get<0>(cur);
        int y = get<1>(cur);
        r = get<2>(cur);
        //cout << x << ' ' << y << ' ' << r << '\n';
        if(x==n-1 && y==m-1) break;
        
        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x>=n||new_y>=m||new_x<0||new_y<0) continue;
            if(arr[new_x][new_y] && r+1>k) continue;
            if(!arr[new_x][new_y]) {
                if(visited[new_x][new_y][r]!=-1) continue;
                Q.push({new_x,new_y,r});
                visited[new_x][new_y][r] = visited[x][y][r]+1;
            } else {
                if(visited[new_x][new_y][r+1]!=-1) continue;
                Q.push({new_x,new_y,r+1});
                visited[new_x][new_y][r+1] = visited[x][y][r]+1;
            }
        }
    }
    cout << visited[n-1][m-1][r] << '\n';
    
}