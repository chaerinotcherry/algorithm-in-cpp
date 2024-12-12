#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin >> str;
    stack<pair<char,int>> S; // 레이저 들어갈 땐 L, 횟수; 그 외의 경우에는 () , index
    int res = 0;
    for(int i=0;i<str.length();i++){
        if(!S.empty() && str[i]==')') {
            if(S.top().first=='(' && S.top().second==i-1) {
                S.pop();
                int num = 1;
                while(!S.empty() && S.top().first == 'L') {
                    num+=S.top().second;
                    S.pop();
                }
                S.push({'L',num});
            } else if (S.top().first=='L' ){
                auto pair = S.top();
                S.pop();
                res+=pair.second+1;
                S.pop();
                int num = pair.second;
                while(!S.empty() && S.top().first == 'L') {
                    num+=S.top().second;
                    S.pop();
                }
                S.push({'L',num});
            }
        }
        else{ 
            S.push({str[i],i});
            
        }
    }
    cout << res;
}