#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
int arr[110];
using namespace std;
int main (){
	int n , k;
	string s;
	map<string,int> m;
	
	cin >> n >> k;

	for(int i = 0; i < n; ++i){
		cin >> s;
		if(m[s] != 1) arr[s.size()]++;
		m[s] = 1;
	}
	cin >> s;
	int total = 0, i = 0;
	while(i < s.size()) total += arr[i++];

	n = floor(total/k) * 5 + total;
	cout << n+1 << " " ;
	n = total + arr[s.size()] - 1;
	cout << ((floor(n/k)) * 5) + n + 1 << endl;

}