#include <bits/stdc++.h>
using namespace std;
int dx[8] = {-2,-1,-2,-1,2,1,2,1};
int dy[8] = {-1,-2,1,2,1,2,-1,-2};
int chess[301][301];
int main(){
    int t; cin >> t;
    while(t--){
        queue<pair<int,int>> Q;
        int l; cin >>l;
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                chess[i][j]=0;
            }
        }
        int rx,ry;//right now
        cin >> rx >>ry;
        int lx, ly; //last
        cin >> lx >>ly;
        Q.push({rx,ry});
        chess[rx][ry]=1;
        if(rx==lx && ry==ly) {
            cout << 0 << '\n';
            continue;
        }
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int i=0;i<8;i++){
                int x = cur.first+dx[i];
                int y = cur.second+dy[i];
                if(x>=l||y>=l||x<0||y<0) continue;
                if(chess[x][y] && chess[x][y] <= chess[cur.first][cur.second]+1) continue;
                chess[x][y] = chess[cur.first][cur.second]+1;
                Q.push({x,y});
            }
        }
        cout << chess[lx][ly]-1 << '\n';
    }
}