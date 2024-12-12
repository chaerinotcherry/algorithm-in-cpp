#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n, arr[2000001], x;
    int pair = 0;
    cin >> n;
    for(int i=0;i<n;i++) {
        int num;
        cin>> num;
        arr[num]++;
    }
    cin >> x;
    for(int i=1; i<(x+1)/2; i++){ 
        if(arr[i] && arr[x-i]) pair++;
    }
    
    cout << pair;
    
    
}