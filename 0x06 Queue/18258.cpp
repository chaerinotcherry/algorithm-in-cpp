#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int n; cin>>n;
    queue<int> Q;
    while(n--){
        string s; cin >>s;
        if(!s.compare("push")){
            int x; cin >> x;
            Q.push(x);
        } else if (!s.compare("front")){
            if(Q.empty()) cout << -1 << '\n';
            else cout << Q.front() << '\n';
        } else if (!s.compare("back")){
            if(Q.empty()) cout << -1 << '\n';
            else cout << Q.back() << '\n';
        } else if (!s.compare("size")){
            cout << Q.size() << '\n';
        } else if (!s.compare("empty")) {
            cout << Q.empty() << '\n';
        } else if (!s.compare("pop")){
            if(Q.empty()) cout << -1 << '\n';
            else {
                cout << Q.front() << '\n';
                Q.pop();
            }
            
        }
    }
}