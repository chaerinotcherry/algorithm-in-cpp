#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    while(n--) {
        string L; cin >> L;
        list<char> lst  = {};
        list<char>::iterator itr = lst.end();
        for(auto a: L){
            if(a=='<'){
                if(itr != lst.begin()) itr--;
            } else if(a == '>') {
                if(itr != lst.end()) itr++;
            } else if(a == '-') {
                if(itr != lst.begin()) {
                    itr--;
                    itr = lst.erase(itr);
                }
            } else {
                lst.insert(itr, a);
            }
        }
        for(auto a: lst) {
            cout << a;
        }
        cout << '\n';
    }
}