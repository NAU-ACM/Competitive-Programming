// author : @BedirT
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int ar[1005];
vector<pair<int,int> > sortedVc;

bool binSearch(vector<pair<int, int> > vc, int l, int r, int key, int i) {
    
    
    while(r-l > 1){
        int mid = l + (r-l) / 2;
        if(vc[mid].first == key && vc[mid].second != i){ 
            printf("%d %d\n", min(i+1,vc[mid].second+1), max(i+1,vc[mid].second+1));
            return true;
        }
        else if(vc[mid].first >= key) r = mid;
        else l = mid;
    }
    
    return false;
}

int main () {
    
    int t, m, n;
    cin >> t;
    
    while(t--){
        
        cin >> m >> n;
        
        // Input
        for (int i= 0 ; i < n ; ++i){
            cin >> ar[i];
            pair<int , int> p(ar[i], i); // Pair for holding the position
            sortedVc.push_back(p);
        }
        
        // Sorting
        sort(sortedVc.begin(), sortedVc.end());
        
        // Searching
        for (int i= 0 ; i < n ; ++i){
            if(binSearch(sortedVc, 0, n-1, m-ar[i], i))
                break;      
        }
        
        sortedVc.clear();
    }
    
}