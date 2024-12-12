#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int A, B, C;
    cin >> A >> B >> C;
    
    int output = A*B*C;
    int arr[11];
    fill(arr, arr+11, 0);
    
    while(output){
        arr[output%10]++;
        output = output/10;
    }
    for(int i=0;i<=9;i++){
        cout << arr[i] << '\n';
    }
}