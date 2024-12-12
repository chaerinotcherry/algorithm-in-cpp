#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int n; cin>>n;
    queue<int> Q;
    for(int i=0;i<n;i++){
        Q.push(i+1);
    }
    for(int i=0;Q.size()>1;i++){
        if(i%2==0){
            Q.pop();
        }
        else {
            int num = Q.front();
            Q.pop();
            Q.push(num);
        }
    }
    cout << Q.front();
}