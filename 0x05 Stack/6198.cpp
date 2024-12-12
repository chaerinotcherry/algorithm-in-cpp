#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    stack<long long> A;
    stack<pair<long long,long long>> B;
    long long n; cin >> n;
    long long total = 0;
    // 1. 일괄 push
    while(n--) {
        long long x; cin >> x;
        A.push(x);
    }
    
    // 2. B에 있는 개수 세기 (단, 작아야함) 크면 즉시 철수
   
    while(!A.empty()){
        long long a = A.top();
        A.pop();
        long long cur = 0;
        while (1) {
            if(B.empty()){
                break;
            }   
            if (B.top().first>=a) {
                break;
            }
            cur += B.top().second+1;
            B.pop();
        }
        B.push(make_pair(a, cur));
        total += cur;
    }
    
    cout << total;
// 3. A에서 pop, B에 push
// 4. 
    
}