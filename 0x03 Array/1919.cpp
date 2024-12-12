#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    
    string first, second; cin >> first >> second;
    int count[27] = {}; // 알파벳 0 0 0 0 .. 0 0 0 0
    int del = 0;
    for(auto a: first) count[a-'a']++;
    for(auto a: second) count[a-'a']--;
    for(int i=0; i<26;i++){
        del += abs(count[i]);
    }
    cout << del;
}