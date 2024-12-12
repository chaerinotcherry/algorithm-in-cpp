#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N;
    cin >> N;
    int max=0;
    
    int arr[10] = {};
    while(N){
        int val = N%10;
        if(val == 9) val=6;
        arr[val]++;
        if(val==6 && max <(arr[val]+1)/2){
            max = (arr[val]+1)/2;
        }
        else if (val!=6 && max < arr[val]){
            max = arr[val];
        }
        N = N/10;
    }
    cout << max;
    
}