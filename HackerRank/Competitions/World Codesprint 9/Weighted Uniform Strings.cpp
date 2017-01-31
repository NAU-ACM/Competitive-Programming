#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int ctArr[100000005];

int main() {
    string s;
    cin >> s; // ascii 'a' is #97
    char hold = s[0];
    int times = 0;
    for(int i = 0; i < s.size() ; ++i){
        if(s[i] == hold){
            times++;
            ctArr[times * (int(s[i]) - 96)]++;
        }
        else{
            times = 1;
            ctArr[int(s[i]) - 96]++;
            hold = s[i];
        }
    }
    int n, t;
    cin >> n;
    for(int i = 0 ; i < n; ++i){
        cin >> t;
        if(ctArr[t])cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}

