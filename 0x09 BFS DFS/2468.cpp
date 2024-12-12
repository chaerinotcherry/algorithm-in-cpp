#include <bits/stdc++.h>
using namespace std;
int board[101][101];
int num[101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int main(){
    //cin.tie(0);ios::sync_with_stdio(0);
    int t; cin >> t;
    fill(num,num+101,0);
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            cin >> board[i][j];
            num[board[i][j]]++;
        }
    }
    int max = 1;
    for(int i=2;i<=100;i++){
        if(num[i]==0) continue;
        int count = 0;
        queue<pair<int,int>> Q;
        int visited[101][101];
        for(int j=0;j<101;j++){
            for(int k=0;k<101;k++){
                visited[j][k]=0;
                
            }
        }
        for(int j=0;j<t;j++){
            for(int k=0;k<t;k++){
                if(board[j][k]<i || visited[j][k]) continue;
                
                Q.push({j,k});
                visited[j][k]=1;
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int l=0;l<4;l++){
                        int x = cur.first + dx[l];
                        int y = cur.second + dy[l];
                        if(x>=t||y>=t||x<0||y<0) continue;
                        if(board[x][y]<i || visited[x][y]) continue;
                        visited[x][y]=1;
                        Q.push({x,y});
                    }
                }
                count++;
                
            }
        }
        if(count > max) max=count;
    }
    cout << max;
    
}