#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int calculate (string s, int p) {

	int arr[200];
	int need = 0;
	for(int j = 1; j <= p; ++j){
		memset(arr, 0, sizeof(arr));
		int mx = 0;
		for(int i = 0; i <= s.size() ; i+=p){
			arr[s[i]]++;
			mx = max(arr[s[i]], mx);
		}
		cout << s.size()/p << " " << mx << endl;
		need += (s.size()/p) - mx;
	}
	if(need < 0) return 0;
	return need;

}

int main () {

	string s;
	int p, mn = 99999999;
	cin >> p >> s;
	for(int i = 1; i <= p; ++i)
		mn = min(calculate(s , i), mn);
	cout << mn << endl;

}