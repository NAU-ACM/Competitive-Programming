// /*
//     Name: 10819 - Trouble of 13-Dots
//     Link: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1760
//     Topic: Dynamic
//     Algo Used: Knapsack
// */
#include <iostream>
#include <cstring>
using namespace std;

int money, n;
int w[200], v[200], d[15000];
bool was[15000];

int main () {

	
	while(cin >> money >> n){
	
		for(int i = 1 ; i <= n ; ++i) cin >> w[i] >> v[i];

		memset(was, 0, sizeof was);
		memset(d, 0, sizeof d);

		was[0] = true;
		d[0] = 0;

		for(int i = 1 ; i <= n ; ++i)
			for(int j = money+200 ; j >= 0; --j)
				if(was[j]){
					was[w[i] + j] = true;
					d[w[i] + j] = max(d[w[i] + j], d[j] + v[i]);	
				}

		int res = 0;
		for(int i = 0 ; i <= money ; ++i)
			res = max(res, d[i]);	

		if(money > 1800)
			for (int i = 2001; i <= money+200; ++i)
				res = max(res, d[i]);

		cout << res << endl;
	}

}
