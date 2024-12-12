#include <bits/stdc++.h>
using namespace std;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N, arr[201]={}, v; // -100 ~ 0 ~ 100 
    // 0 ~ 100 ~ 200
    cin >> N;
    for(int i=0;i<N;i++) {
        int num; cin >> num;
        arr[num+100]++;
    }
    //arr은 1~200 중 해당 수 ++
    //0 0 0 0 1 0 0 0 0 0 1 이런식
    cin >> v;
    cout << arr[v+100];

}
    