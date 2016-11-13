/*
ID: bedir.t1
PROG: milk2
LANG: C++11
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


int main (){
    int n,a,b;
    freopen("milk2.in", "r", stdin);    
    freopen("milk2.out", "w", stdout);  
    cin >> n;
    int mx = 0, mn = 0;
    vector<pair<int, int> > vc;
    while(n--){
        cin >> a >> b;
        pair<int, int> pp(a, b);    
        vc.push_back(pp);    
    }
    sort(vc.begin() , vc.end());
    for(int i = 1 ; i < vc.size(); ++i){
        if(vc[i].first <= vc[i-1].second){
            vc[i-1].second = max(vc[i].second,vc[i-1].second);
            vc.erase (vc.begin()+(i));
            // cout << vc[i-1].first << " " << vc[i-1].second << endl;
            i--;
        }

    }
    int oldb = vc[0].first;
    for(int i =0 ; i < vc.size(); ++i){
        a = vc[i].first, b = vc[i].second;
        mx = max(b - a, mx);   
        mn = max(a - oldb, mn);
        oldb = b;
    }
    cout << mx << " " << mn << endl;
}
