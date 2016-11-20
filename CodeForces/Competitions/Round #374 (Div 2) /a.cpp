#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
 
using namespace std;
int main (){
	int n , ans = 0;
	std::vector<int> vc;
	string s;
	cin >> n >> s;

	for(int i = 0 ; i < s.size() ; ++i){
		int j = 0;
		while(s[i+j] == 'B'){
			j++;
		}
		if(j){
			ans++;	
			vc.push_back(j);
		} 
		i+=j;
	}
	cout << ans << endl;
	for(int i = 0; i < vc.size(); ++i){
		cout << vc[i] << " ";
	}
	cout << endl;
}
