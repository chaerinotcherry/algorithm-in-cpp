#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int n; cin>>n;
    deque<int> DQ;
    while(n--){
        string s; cin>>s;
        if(!s.compare("push_front")){
            int x; cin >> x;
            DQ.push_front(x);
        }else if(!s.compare("push_back")){
            int x; cin >> x;
            DQ.push_back(x);
        }else if(!s.compare("pop_front")){
            if(DQ.empty()) cout << -1 << '\n';
            else {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        }else if(!s.compare("pop_back")){
            if(DQ.empty()) cout << -1 << '\n';
            else {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        }else if(!s.compare("size")){
            cout << DQ.size() << '\n';
        }else if(!s.compare("empty")){
            cout << DQ.empty() << '\n';
        }else if(!s.compare("front")){
            if(DQ.empty()) cout << -1 << '\n';
            else cout << DQ.front() << '\n';
        }else if(!s.compare("back")){
            if(DQ.empty()) cout << -1 << '\n';
            else cout << DQ.back() << '\n';
        }
    }
}