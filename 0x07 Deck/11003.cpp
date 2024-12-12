#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    
    int n,l; cin >> n>>l;
    deque<pair<int,int>> D;
    int i;
    for( i=0;i<n;i++){
        int x; cin >> x;
        
        if(!D.empty() && i-l>=0 && D.front().second<=i-l){
            D.pop_front();
        }
        while(!D.empty() && D.back().first>x) {
            D.pop_back();
        }
        D.push_back({x,i});
        cout << D.front().first << ' ';
    }
    
}