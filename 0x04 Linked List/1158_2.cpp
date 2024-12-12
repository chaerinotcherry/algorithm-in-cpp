#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    
    int N, K; cin >> N >> K;
    list<int> L = {};
    for(int i=1;i<=N;i++){
        L.push_back(i);
    }
    cout << '<';
    list<int>::iterator t = L.end();
    while(N--){
        int n = K;
        while(n--) {
            t++;
            if(t==L.end()) t=L.begin();
        }
        cout << *t;
        if(N!=0) cout << ", ";
        else cout << '>';
        t = L.erase(t);
        t--;
        
    }
}