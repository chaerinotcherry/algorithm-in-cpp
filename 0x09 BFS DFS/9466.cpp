#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int visited[100001];
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int t; cin >>t;
    
    while(t--){
        int n; cin >> n;
        int count = n;
        for(int i=1;i<=n;i++){
            cin >> arr[i];
            visited[i]=0;
        }
        
        for(int i=1;i<=n;i++){
            if(visited[i]!=0) continue;
            int next = i;
            while(1){
                if(visited[next]==-i) {
                    int index = arr[next]; 
                    visited[next] = 1;
                    count--;
                    while(next!=index){
                        visited[next] = 1;
                        count--;   
                        index = arr[index];
                    }
                    break;
                }
                if(visited[next]==1 || visited[next]<0) {
                    int index = arr[i]; 
                    while(next!=index){
                        index = arr[index];
                    }
                    break;
                }
                visited[next] = -i;
                next = arr[next];
            }
            if(visited[i]==0) visited[i]=-1;
        }
        
        cout << count << '\n';
    }
}