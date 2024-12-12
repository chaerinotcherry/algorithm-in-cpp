#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    stack<int> s = {};
    while(N--){
        string str; cin >> str;
        if(str.compare("push")==0){
            int X; cin >> X;
            s.push(X);
        } else if (str.compare("pop")==0){
            if(!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            }
            else cout << -1 << '\n';
        } else if (str.compare("size")==0){
            cout << s.size() << '\n';
        } else if (str.compare("empty")==0){
            cout << s.empty() << '\n';
        } else if (str.compare("top")==0){
            if(!s.empty()) cout << s.top() << '\n';
            else cout << -1 << '\n';
        }
    }
}