// 남 여 따로; 한방에는 같은 학년; 한방에 한명 가능
// 한방 배정 가능 인원 K
// 최소 개수의 방; 0개도 있음
// 일단 다 모으고 (++)
// K로 각각 나누어 합쳐. K+1
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N, K;
    cin >> N >> K;
    int arr[2][6]; // 학생 수수
    for(int i=0;i<2;i++){
        for(int j=0;j<6;j++){
            arr[i][j]=0;
        }
    }
    for(int i=0;i<N;i++){
        int s, y;
        cin >> s >> y;
        arr[s][y-1]++;
    }
    int val;
    int sum = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<6;j++){
            if (arr[i][j]==0) val=0;
            else val = (arr[i][j]+K-1)/K;
            sum += val;
        }
    }
    cout << sum;
}