#include <bits/stdc++.h>
using namespace std;
int main () {
    cin.tie(0); ios::sync_with_stdio(0);
    int arr[501][501];
    bool visited[501][501] = {0};
    queue<pair<int,int>> Q;
    int n, m; cin >> n >> m;
    int curmax = 0, max=0, count=0;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            if(!visited[i][j] && arr[i][j]){
                visited[i][j]=1;
                Q.push({i,j});
            } else {
                continue;
            }
            curmax = 1;
            while(!Q.empty()){
                auto cur = Q.front();
                Q.pop();
                for(int i=0;i<4;i++){
                    int cur_dx = cur.first + dx[i];
                    int cur_dy = cur.second + dy[i];
                    if(cur_dx<0 || cur_dx>=n || cur_dy<0 || cur_dy>=m) continue;
                    if(visited[cur_dx][cur_dy] || !arr[cur_dx][cur_dy]) continue;
                    visited[cur_dx][cur_dy] = 1;
                    Q.push({cur_dx,cur_dy});
                    curmax++;
                }
            }
            count++;
            if(curmax>max) max=curmax;
            
        }
    }
    cout << count << '\n';
    cout << max;
}