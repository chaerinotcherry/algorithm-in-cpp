#include <bits/stdc++.h>
using namespace std;
int main(){
    //cin.tie(0); ios::sync_with_stdio(0);
    
    list<char> lst = {};
    string str; cin >> str;
    for (auto a:str) lst.push_back(a);
    list<char>::iterator itr = lst.end();
        
    int n; cin >> n;
    
    while(n--){
        char alp; cin >> alp;
        if (alp == 'P') {
            char var; cin >> var;
            lst.insert(itr, var);
        } else if (alp == 'L') {
            if(itr!=lst.begin()) itr--;
        } else if (alp == 'D') {
            if (itr!=lst.end()) itr++;
        } else if (alp == 'B') {
            if (itr!=lst.begin()) {
                itr--;
                itr = lst.erase(itr);
            }
        }
    }
    for(auto a:lst){
        cout << a;
    }
}