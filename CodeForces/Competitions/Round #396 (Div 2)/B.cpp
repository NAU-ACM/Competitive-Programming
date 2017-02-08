#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a+n);
	for (int i = 2; i < n; ++i){
		int x = a[i];
		int y = a[i-1];
		int z = a[i-2];
		if(x > y+z){
			cout << "YES";
			exit(0);
		}
	}
	cout << "NO";
}