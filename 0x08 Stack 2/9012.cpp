#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int n; cin>>n;
    while(n--){
        string x; cin>>x;
        stack<char> S;
        for(auto i:x){
            if(S.empty()){
                S.push(i);
                if(i==')') break;
            } else {
                if(i==')' && S.top()=='(') S.pop();
                else if(i==')') break; 
                else S.push(i);
            }
        }
        if(S.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}