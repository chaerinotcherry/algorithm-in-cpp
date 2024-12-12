#include <bits/stdc++.h>
using namespace std;
int main() {
        cin.tie(0); ios::sync_with_stdio(0);
        long long n; cin >> n;
        while(n !=0){
            
            stack<pair<long long,long long>> S; // x, 그리고 추가된 index
             
            long long maxarea = 0;
            for(long long i=0; i<n; i++) {
                long long x; cin >> x;
                long long second = i;
                while(!S.empty() && S.top().first>x){
                    long long first = S.top().first;
                    second = S.top().second;
                    maxarea = max(maxarea, first*(i-second));
                    S.pop();
                }
                if(S.empty() || S.top().first != x) {
                    S.push({x,second});
                }
            }
            
            while(!S.empty()){
                long long first = S.top().first;
                long long second = S.top().second;
                maxarea = max(maxarea, first*(n-second));
                
                S.pop();
            }
            cout << maxarea << '\n';
            cin >> n;
            
            
        
        }
    
    
}