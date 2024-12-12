#include <bits/stdc++.h>
using namespace std;
int main(){
    //cin.tie(0); ios::sync_with_stdio(0);
    while(1){
        string period; getline(cin,period);
        int able = 1;
        stack<char> S;
        if(!period.compare(".")) {
            break;
        }
        for(int i=0;able==1 && i<period.length();i++) {
            if(period[i]=='.') {
                break;
            }
            if(period[i]=='['|| period[i]=='(') {
                S.push(period[i]);
            }
            else if(period[i] == ']'){
                if(!S.empty() && S.top()=='[') S.pop();
                else {
                    able=0;
                }
            }
            else if(period[i]==')'){
                if(!S.empty() && S.top()=='(') S.pop();
                else {
                    able=0;
                }
            } 
        }
        if(able && S.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    
    
    
}