//먼저 표시하기 1, 2, 3 land개수세듯이
//여지껏 최단거리는 visited이용해서 전꺼+1한 값이 visited 덮어씌운는 식으로 했음
#include <bits/stdc++.h>
using namespace std;
#define MIN(x,y) (x<y)?(x):(y);
int arr[101][101];
int counted[101][101];
int visited[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            counted[i][j]=0;
            visited[i][j]=0;
        }
    }
    //number the lands from 2!
    queue<pair<int,int>> Q;
    int track = 2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(counted[i][j] || !arr[i][j]) continue;
            Q.push({i,j});
            counted[i][j]=1;
            arr[i][j] = track;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int i=0;i<4;i++){
                    int x = cur.first + dx[i];
                    int y = cur.second + dy[i];
                    if(x>=n||y>=n||x<0||y<0) continue;
                    if(counted[x][y] || !arr[x][y]) continue;
                    Q.push({x,y});
                    arr[x][y]=track;
                    counted[x][y]=1;
                }
            }
            track++;
        }
    }
    
    int min_dist = 999999;
    int h = 1;
    //최솟값
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0) continue;
            queue<tuple<int, int,int>> T;
            int temp = arr[i][j];
            T.push({i,j,0});
            int dist = 0;
            int isDone = 0;
            while(!T.empty()) {
                auto cur = T.front(); T.pop();
                for(int i=0;i<4;i++){
                    int x = get<0>(cur) + dx[i]; 
                    int y = get<1>(cur) + dy[i];
                    int new_dist = get<2>(cur);
                    if(x>=n||y>=n||x<0||y<0) continue;
                    if(arr[x][y]==temp || visited[x][y]==h) continue;
                    if(arr[x][y]==0){ 
                        //cout << "if " << x << ' ' << y << '\n';
                        if(dist>=new_dist+1) {
                            isDone = 1;
                            break;
                        }
                        visited[x][y] = h;
                        T.push({x,y,new_dist+1});
                    }
                    else {
                        //cout << "else " << x << ' ' << y << ' ' << new_dist << '\n';
                        min_dist = MIN(min_dist, new_dist);
                        isDone = 1;
                        break;
                    }
                    
                }
                if(isDone) break;
            }
            h++;
        }
    }
    cout << min_dist << '\n';
}