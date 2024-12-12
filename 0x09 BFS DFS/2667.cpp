#include <bits/stdc++.h>
using namespace std;
char board[26][26];
int visited[26][26];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int,int>> Q;
int main(){
    //cin.tie(0);
    //ios::sync_with_stdio(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            visited[i][j]=0;
        }
    }
    
    int count = 0;
    vector<int> areas;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]!='0' && !visited[i][j]) {
                visited[i][j]=1;
                Q.push({i,j});
                int area = 1;
                count++;
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int i=0;i<4;i++){
                        int x = cur.first+dx[i];
                        int y = cur.second+dy[i];
                        if(x>=n||y>=n||x<0||y<0) continue;
                        if(board[x][y]=='0' || visited[x][y]) continue;
                        area++;
                        visited[x][y] = 1;
                        Q.push({x,y});
                        
                    }
                }
                areas.push_back(area);
            }
        }
    }
    cout << count << '\n';
    sort(areas.begin(),areas.end());
    for(auto a:areas) cout << a << '\n';
}