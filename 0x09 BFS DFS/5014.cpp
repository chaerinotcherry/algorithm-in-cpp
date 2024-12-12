2468.v#include <bits/stdc++.h>
using namespace std;
long visited[1000001];
queue<pair<int,int>> Q;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int F, S, G, U, D; cin >> F >> S >> G >> U >> D;
    //f 전체 s는 현재 g는 목표 u는 up d는 down
    if(S==G) {
        cout << 0;
        return 0;
    }
    for(int i=0;i<F;i++){
        visited[i]=0;
    }
    
    queue<int> Q;
    visited[S]=1;
    Q.push(S);
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur+U<=F && (visited[cur+U]==0 || visited[cur+U]>visited[cur]+1)){
            
            visited[cur+U]=visited[cur]+1;
            if(cur+U==G) {
                break;
            }
            Q.push(cur+U);
            
        }
        if(cur-D>0 && (visited[cur-D]==0 || visited[cur-D]>visited[cur]+1)){
            
            visited[cur-D]=visited[cur]+1;
            if(cur-D==G) {
                break;
            }
            Q.push(cur-D);
        }
        
    }
    if(visited[G]) cout << visited[G]-1 << '\n';
    else cout << "use the stairs";
}