//0초 후:: 두개 비교 필요
#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int main(){
    for(int i=0;i<100000;i++){
        arr[i]=0;
    }
    int n, k; cin >> n >> k;
    queue<int> Q;
    int sec = 0;
    Q.push(n);
    arr[n] = 1;
    Q.push(-1);
    
    while(!Q.empty()){
        int n = Q.front(); Q.pop();
        //cout << n << '\n';
        if(n==-1) {
            sec++;
            Q.push(-1);
            continue;
        }
        for(int i=n;i<=k;i=i*2){
            arr[i]=1;
            if(i==k) {
                cout << sec;
                return 0;
            } 
            if(i==0) break;
        }
        for(int i=n;i<=100000;i=i*2){ 
            if(i+1<=100000 && !arr[i+1]) {Q.push(i+1); arr[i+1]=1;}
            if(i-1>=0 && i-1<=100000 && !arr[i-1]) {Q.push(i-1); arr[i-1]=1;}
            if(i==0) break;
        }
        
        
    }
    
}