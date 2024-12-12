// 1000 순회하며 알파벳 ++
// 각 문자열 개수 같으면 possible 아닌 즉시 impossible
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N; cin >> N;
    while(N--){
        string first, second;
        cin>> first >> second;
        int count1[27] = {}, count2[27] = {};
        for(int i=0;i<first.length();i++){
            count1[first[i]-'a']++;
        }
        for(int i=0;i<second.length();i++){
            count2[second[i]-'a']++;
        }
        int i;
        for(i=0;i<26;i++){
            if(count1[i]!=count2[i]){
                cout << "Impossible" << '\n';
                break;
            }
        }
        if (i==26) cout << "Possible" << '\n';
        
        
    }
}