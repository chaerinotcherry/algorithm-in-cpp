// 0
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    
    int K; cin >> K;
    stack<int> s;
    long long sum = 0;
    while(K--){
        long long num; cin >> num;
        if(num==0) {
            sum-=s.top();
            s.pop();
        }
        else s.push(num);
        sum += num;
    }
    cout << sum;
}