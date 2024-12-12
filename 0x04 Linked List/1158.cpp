#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    list<int> L;
    for(int i=0;i<n;i++){
        L.push_back(i+1);
    }
    list<int>::iterator itr = L.begin();
    cout << "<";
    while(n--){
        for(int i=0;i<k-1;i++){
            if(next(itr)==L.end() || itr==L.end()){
                itr = L.begin();
            }
            else itr++;
        }
        cout << *itr;
        if(n!=0) cout << ", ";
        if(next(itr)!=L.end()) itr = L.erase(itr);
        else {
            L.erase(itr);
            itr = L.begin();
        }
    }
    cout << ">";
}