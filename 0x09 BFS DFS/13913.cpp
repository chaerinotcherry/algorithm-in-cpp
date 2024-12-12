#include <bits/stdc++.h>
using namespace std;
int arr[100001];
void find(int fst, int sec){
    if(sec==0) {
        return;
    }
    if(fst-1>=0 && arr[fst-1] == sec-1) fst=fst-1;
    else if (fst+1<=100000 && arr[fst+1]==sec-1) fst=fst+1;
    else if (fst%2==0 && arr[fst/2]==sec-1) fst=fst/2;
    find(fst,sec-1);
    cout << fst << ' ';
}

int main() {
    int org_n, k; cin >>org_n >> k;
    queue<pair<int,int>> Q; 
    for(int i=0;i<100001;i++) arr[i]=-1;
    Q.push({org_n,0});
    arr[org_n]=0;
    while(!Q.empty()) {
        auto n = Q.front(); Q.pop();
        //cout << n.first<< '\n';
        if(n.first==k) {
            cout << n.second << '\n';
            int sec = n.second;
            int fst = n.first;
            find(fst,sec);
            cout << fst << '\n';
            break;
        }
        if(n.first+1<=100000 && arr[n.first+1]==-1) {
            Q.push({n.first+1, n.second+1});
            arr[n.first+1] = n.second+1;
        }
        if(n.first-1>=0 && arr[n.first-1]==-1) {
            Q.push({n.first-1, n.second+1});
            arr[n.first-1] = n.second+1;
        }
        if(n.first*2<=100000 && arr[n.first*2]==-1){
            Q.push({n.first*2, n.second+1});
            arr[n.first*2] = n.second+1;
        }
    }
}