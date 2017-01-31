#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n , k , xq, yq, x ,y;
    cin >> n >> k >> xq >> yq;
    int d = yq-1, u = n-yq, l = xq-1, r = n-xq, ur = min(n-xq, n-yq), ul = min(xq-1, n-yq), dl = min(xq-1, yq-1), dr = min(n-xq, yq-1);
    // cout << u << " " <<  ur << " " << r << " " << dr << " " << d << " " << dl << " " << l << " " << ul << endl;
    for(int i = 0 ; i < k ; ++i){
        cin >> x >> y;
        if(y == yq){
            if(x < xq)  l = min(l, xq - x - 1);        
            else        r = min(r, x - xq - 1);
        }
       
        if(x == xq){
            if(y > yq)  u = min(u, y - yq - 1);        
            else        d = min(d, yq - y - 1);
        }
        
        if(yq - xq == y - x){
            if(y < yq)  dl = min(dl, yq - y - 1);        
            else        ur = min(ur, y - yq - 1);
        }
        
        if(yq + xq == y + x){
            if(y < yq)  ul = min(ul, yq - y - 1);        
            else        dr = min(dr, y - yq - 1);
        }
            
    }
    // cout << u << " " <<  ur << " " << r << " " << dr << " " << d << " " << dl << " " << l << " " << ul << endl;
    cout << u + ur + r + dr + d + dl + l + ul << endl;
    
    return 0;
}
