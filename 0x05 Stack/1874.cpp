// 1 2 3 4 순 push
// 

#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int works = 1;
    int track = 0;
    int n; cin >> n;
    stack<int> s;
    list<char> ans;
    while(n--){
        int num; cin >>num;
        if (!s.empty() && num < s.top()){
            cout << "NO";
            works = 0;
            break;
        } else {
            for(int i=track+1; i<=num; i++){
                ans.push_back('+');
                s.push(i);
            }
            ans.push_back('-');
            s.pop();
            if(track < num) track = num;
        }
    }
    if(works) {
        for(auto i: ans) cout << i << '\n';
    }
}