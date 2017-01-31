#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void calc(int x){
    int t = x;
    if(x < 38) cout << x << endl;
    else{
        while(t++ % 5 != 0);
        if(--t - x < 3) cout << t << endl;
        else cout << x << endl;    
    }
}

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i  < n ; ++i){
        cin >> k;
        calc(k);
    }
    return 0;
}


