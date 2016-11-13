/*
    Name: 10487 - Closest Sums
    Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1428
    Topic: Complete Search
    Algo Used: Binary Search
    Author: BT
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,key;
int arr[1001];
vector<int> vc;

int binarySearch(vector<int> v, int l, int r, int key){
    int m;
    if(l == r) return v[0];
    while(l != r-1){
        m = (l+r)/2;
        if(v[m] <= key) l = m;
        else r = m;
    }
    return ((abs(key-v[l]) >= abs(key-v[r])) ? v[r] : v[l]);
}

int main (){

    cin >> n;
    int casenum = 1;
    while(n != 0){
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                vc.push_back(arr[j]+arr[i]);
        cin >> m;
        cout << "Case " << casenum++ << ":\n";
        sort(vc.begin(), vc.end());
        //for (int i = 0; i < vc.size(); i++) cout << vc[i] << " ";
        while(m--){
            cin >> key;
            cout << "Closest sum to " << key << " is "<< binarySearch(vc, 0, vc.size()-1, key) <<".\n";
        }
        vc.clear();
        cin >> n;
    }

}
