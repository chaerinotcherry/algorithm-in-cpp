#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[301][301];
int visited[301][301];
int visited2[301][301];
int n,m; 
int phasecount = 1;
// zero count 하는 행위
void run() {
    for(int j=0;j<n;j++){
        for(int k=0;k<m;k++){
            if(!arr[j][k]) continue;
            visited[j][k]=phasecount;
            for(int i=0;i<4;i++){
                int new_x = j+dx[i];
                int new_y = k+dy[i];
                if(new_x>=n || new_y>=m || new_x<0 || new_y<0) continue;
                if(!arr[new_x][new_y] && arr[j][k]>0 && visited[new_x][new_y]!=phasecount) {
                    arr[j][k]--;
                    //cout << "z: " <<zerocount << " j k" << j << ' ' << k << '\n';
                } 
            }   
        }
    }
}

int landcount() {
    int land_count = 0;
    queue<pair<int,int>> Q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited2[i][j] = 0;
        }
    }
    for(int j=0;j<n;j++){
        for(int k=0;k<m;k++){
            if(visited2[j][k] || !arr[j][k]) continue;
            Q.push({j,k});
            visited2[j][k]=1;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int i=0;i<4;i++){
                    int new_x = cur.first+dx[i];
                    int new_y = cur.second+dy[i];
                    if(new_x>=n || new_y>=m || new_x<0 || new_y<0) continue;
                    if(visited2[new_x][new_y] || !arr[new_x][new_y]) continue;
                    Q.push({new_x,new_y});
                    visited2[new_x][new_y]=1;
                }   
            }
            land_count++;
            //cout << land_count << ' ' << phasecount<< '\n';
            if(land_count>=2){
                return 1;
            }
        }
    }
    if(land_count==0) return -1;
    return 0;
}
int main(){
    //cin.tie(0); ios::sync_with_stdio(0);
    //cout << "Hi";
    cin >> n>> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            visited[i][j]=0;
        }
    }
    while(1){
        int val = landcount();
        if(val==1) {
            cout << phasecount-1 << '\n';
            return 0;
        } else if (val==-1) {
            break;
        }
        run();
        
        phasecount++;
    }
    cout << 0 << '\n';
}