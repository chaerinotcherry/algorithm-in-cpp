#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    string S;
    int alp[30];
    fill(alp, alp+30, 0);
    cin >> S;
    for(int i=0;i<S.length();i++){
        int order = S[i] - 'a';
        alp[order]++;
    }
    for(int i=0;i<26;i++){
        cout << alp[i] << ' ';
    }
}
