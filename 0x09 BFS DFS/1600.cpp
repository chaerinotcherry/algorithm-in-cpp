// //말 횟수 저장
// if(K보다 커요) continue;
// bfs임으로 무조건 빨리 끝나면 그게 바로 최소.
// visited는 체크해줘야함 근데 어떻게??
// - 모든 경우의 수 체크할거니깐

#include <bits/stdc++.h>
using namespace std;
int arr[201][201];
int visited[201][201][31];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int dx_2[8] = {-2,-2,-1,-1,1,1,2,2};
int dy_2[8] = {1,-1,2,-2,2,-2,1,-1};
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int k; cin >> k;
    int w, h; cin >> w >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> arr[i][j];
        }
    }
    for(int l=0;l<=k;l++){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                
                    visited[i][j][l] = -1;
            }
        }
    }
    queue<tuple<int,int,int>> Q;
    Q.push({0,0,0});
    visited[0][0][0]=0;
    int found = 0;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        int r_time = get<2>(cur);
        //cout << get<0>(cur) << ' ' << get<1>(cur) << ' ' << get<2>(cur) << ' ' <<        visited[get<0>(cur)][get<1>(cur)][r_time] << '\n';
        //r 가능한 경우
        
        if(get<0>(cur)==h-1 && get<1>(cur)==w-1) {
            cout << visited[get<0>(cur)][get<1>(cur)][r_time];
            return 0;
        }
        if(r_time<k){
            for(int i=0;i<8;i++){
                int x = get<0>(cur) + dx_2[i];
                int y = get<1>(cur) + dy_2[i];
                if(x>=h||y>=w||x<0||y<0) continue;
                if(arr[x][y] ==1) continue;
                //cout << "visited: " << visited[x][y][r_time+1] << '\n'; 
                if(visited[x][y][r_time+1]!=-1) continue;
                Q.push({x,y,r_time+1});
                visited[x][y][r_time+1] = visited[get<0>(cur)][get<1>(cur)][r_time] +1 ;
            }
        }
        for(int i=0;i<4;i++){
            int x = get<0>(cur) + dx[i];
            int y = get<1>(cur) + dy[i];
            ///cout << visited[x][y][r_time];
            if(x>=h||y>=w||x<0||y<0) continue;
            if(arr[x][y]==1) continue;
            if(visited[x][y][r_time]!=-1) continue;
            Q.push({x,y,r_time});
            visited[x][y][r_time] = visited[get<0>(cur)][get<1>(cur)][r_time] +1 ;
        }
        
    }
    cout << -1 << '\n';
}