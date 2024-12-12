#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    long long a, b, c, prod;
    cin >> a >> b >> c;
    prod = a * b * c;
    int arr[10];
    for(int i=0;i<10;i++) arr[i]=0;
    while(prod){
        arr[prod%10]++;
        prod/=10;
    }
    for(int i=0; i<10; i++){
        cout << arr[i] << '\n';
    }
}