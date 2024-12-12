#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int n; cin >>n;
    int index = 0;
    stack<pair<int,int>> s;
    while(n--){
        int x; cin>>x;
        while(1){
            if(s.empty()){
                cout << 0 << ' ';
                break;
            }
            //값 클때까지 pop
            auto comp = s.top();
            if(comp.first > x) {
                cout << comp.second << ' ';
                break;
            } else {
                if(!s.empty()) s.pop();
            }
        }
        s.push(make_pair(x, ++index));
    }
    
}