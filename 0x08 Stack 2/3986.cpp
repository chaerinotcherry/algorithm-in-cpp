#include <bits/stdc++.h>
using namespace std;
int main(){
    //cin.tie(0); ios::sync_with_stdio(0);
    int n; cin >> n;
    int count = 0;
    for(int i=0;i<n;i++){
        stack<char> S;
        string str; cin >>str;
        for(auto word:str){
            if(S.empty()){
                S.push(word); 
            } else {
                if(S.top()==word){
                    S.pop();
                } else {
                    S.push(word);
                } 
            }
        }
        if(S.empty()) count++;
    }
    cout << count;
}