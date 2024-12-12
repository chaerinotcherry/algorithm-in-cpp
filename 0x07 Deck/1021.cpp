#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    deque<int> DQ;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        DQ.push_back(i+1);
    }
    int res = 0;
    while(m--){
        int x; cin >> x;
        if(x==DQ.front()) {
            DQ.pop_front();
        } else {
            int num = 1;
            for(;*(DQ.begin()+num)!=x && *(DQ.end()-num)!=x;){
                num++;
            }
            if(*(DQ.begin()+num)==x){
                while(DQ.front()!=x){
                    int a = DQ.front();
                    DQ.pop_front();
                    DQ.push_back(a);
                    res++;
                }
                DQ.pop_front();
            } else {
                while(DQ.front()!=x) {
                    int a = DQ.back();
                    DQ.pop_back();
                    DQ.push_front(a);
                    res++;
                }
                DQ.pop_front();
            }
        }
    }
    cout << res;
}