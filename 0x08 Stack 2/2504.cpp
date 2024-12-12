#include <bits/stdc++.h>
using namespace std;
int main() { 
    stack<pair<char,int>> S;
    string str; cin >> str;
    int res = 0;
    int nope = 0;
    for(int i=0;i<str.length();i++){
        if(!S.empty() && str[i]==')'){
            if(S.top().first=='(') {
                S.pop();
                S.push({'n',2});
            } else if (S.top().second>=0) {
                int val = 0;
                while(!S.empty() && S.top().second != -1) {
                    val+= S.top().second;
                    S.pop();
                }
                if(S.empty() || S.top().first!='(') {
                    nope = 1; break;}
                S.pop();
                S.push({'n',val*2});
            } else {
                nope = 1;
                break;
            }
        } else if(!S.empty() && str[i]==']'){
            if(S.top().first=='[') {
                S.pop();
                S.push({'n',3});
            } else if (S.top().second>=0) {
                int val = 0;
                while(!S.empty() && S.top().second != -1) {
                    val+= S.top().second;
                    S.pop();
                }
                if(S.empty() || S.top().first!='[') {
                    nope = 1; break;}
                S.pop();
                S.push({'n',val*3});
            } else {
                nope = 1;
                break;
            }
        }
        else {
            S.push({str[i],-1});
        }
       
    }
    if(nope || S.empty()) cout << '0';
    else {
        while(!S.empty()) {
            if(S.top().second==-1) {
                cout << '0';
                nope = 1;
                break;
            }
            res += S.top().second;
            S.pop();
        }
        if(!nope) cout << res;
    }
}