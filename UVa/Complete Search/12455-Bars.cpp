/*
    Name: 12455 - Bars
    Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3886
    Topic: Complete Search
    Algo Used: Bit Manipulation
*/
#include <iostream>
using namespace std;
int par[20], p, N , t;
int main() {
	cin >> t;
	while(t--){
		cin >> N >> p;
		bool ok = false;
		for (int i = 0; i < p; i++) cin >> par[i];
		for (int i = 0; i < (1 << p); i++) {
			int sum = 0;
			for (int j = 0; j < p; j++)
				if (i & (1 << j))
					sum += par[j];
			if(sum == N) {
				ok = true;
				break;
			}
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
