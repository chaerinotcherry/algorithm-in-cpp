#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    stack<pair<long long,long long>> S; // 값, 횟수
    long long n; cin >> n;
    long long count = 0;
    
    for(int i=0;i<n;i++){
        long long x; cin >> x;
        long long sec=-1;
        long long fst;
        while(1){
            if(S.empty()){
                break;
            }
            if(S.top().first > x){
                count++;
                break;
            } 
            fst = S.top().first;
            sec = S.top().second;
            count+=sec;
            S.pop();
    
        }
        if(sec!=-1 && x==fst){
            S.push(make_pair(x,sec+1));
            
        } else {
            S.push(make_pair(x,1));
        }
    }
    cout << count;
}
