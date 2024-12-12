#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    char key[1001], a[27], b[27];
    cin >> key;
    for(int i=0;i<27;i++){
        a[i]=0; b[i]=0;
    }
    for(int i=0;i<strlen(key);i++){
        a[(int)key[i]-'a']++;
    }
    cin >> key;
    for(int i=0;i<strlen(key);i++){
        b[(int)key[i]-'a']++;
    }
    int res = 0;
    for(int j=0; j<26; j++){
        if(a[j]!=b[j]){
            res+=abs(a[j]-b[j]);
        }
    }
    cout << res;
}