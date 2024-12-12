#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        string p; cin >> p;
        int n; cin >> n;
        deque<int> D;
        string arr; cin >> arr;
        int sep = 0;
        for(int i=1;i<arr.length();i++){
            if(arr[i]==',' || arr[i]==']') {
                if(sep) D.push_back(sep);
                sep = 0;
            }
            else {
                if(sep) {
                    int arraynum = arr[i] - '0';
                    sep = sep * 10 + arraynum;
                } else {
                    sep = arr[i]-'0';
                }
            }
        }
        int inverse = 0;
        int print = 1;
        for(int i=0;i<p.length();i++){
            if(p[i]=='R'){
                if(inverse) inverse=0;
                else inverse=1;
            } else if (p[i]=='D'){
                if(inverse) {
                    if(!D.empty()) {
                        D.pop_back();
                    } else {
                        cout << "error\n";
                        print = 0;
                        break;
                    }
                } else {
                    if(!D.empty()) {
                        D.pop_front();
                    } else {
                        cout << "error\n";
                        print = 0;
                        break;
                    }
                }
            } else {
                cout << "error\n";
                print = 0;
                break;
            }
        }
        if(print){
            cout << '[';
            if(inverse){
                int size = D.size();
                for(int i=0;i<size;i++){
                    cout << D.back();
                    D.pop_back();
                    if(i!=size-1) cout << ",";
                }
            } else {
                int size = D.size();
                for(int i=0;i<size;i++){
                    cout << D.front();
                    D.pop_front();
                    if(i!=size-1) cout << ",";
                }
            }
            cout << "]\n";
            
        }
        
    }
    
}