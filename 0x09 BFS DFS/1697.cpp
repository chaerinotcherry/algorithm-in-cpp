#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int main(){
    fill(arr, arr+100001, 0);
    int n, k; cin >> n >> k;
    queue<int> Q; // queue 위치, 소요 시간
    Q.push(n);
    arr[n] =1;
    if(n==k){
      cout << 0;
        return 0;
    } 
   
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur-1>=0 && (!arr[cur-1] || arr[cur-1]>arr[cur]+1)){
            arr[cur-1]=arr[cur]+1;
            Q.push(cur-1);
            if(cur-1==k) {
                cout << arr[cur-1]-1;
                break;
            }
        }
        if(cur+1<=100000 &&(!arr[cur+1] || arr[cur+1]>arr[cur]+1)){
            arr[cur+1]=arr[cur]+1;
            Q.push(cur+1);
            if(cur+1==k) {
                cout << arr[cur+1]-1;
                break;
            }
        }
        if(2*cur<=100000&& (!arr[cur*2] || arr[cur*2]>arr[cur]+1)){
            arr[2*cur]=arr[cur]+1;
            Q.push(2*cur);
            if(2*cur==k) {
                cout << arr[2*cur]-1;
                break;
            }
        }
    }
    
}
// 마이너스?