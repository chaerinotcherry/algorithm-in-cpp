#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int arr[1000005];
    for(int i=0;i<n;i++) arr[i] = -1;
    stack<pair<int,int>> S;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        while(1){
            
            if(S.empty() || S.top().first>=x) {
                S.push(make_pair(x,i));
                break;
            }
            arr[S.top().second] = x;
            S.pop();
        } 
    }
    for(int i=0;i<n;i++) cout << arr[i] << ' ';
}