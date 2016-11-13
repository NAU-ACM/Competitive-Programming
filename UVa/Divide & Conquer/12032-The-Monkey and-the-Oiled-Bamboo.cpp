/*
    Name: 12032 - The Monkey and the Oiled Bamboo
    Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3183
    Topic: Divide & Conquer
    Algo Used: -
*/
#include <iostream>
#include <vector>
using namespace std;

int t, n, a;
vector<int> vc;

int main () {

	cin >> t;
	int counter = 1;
	while (t--) {
		cin >> n;
		int maxx = 0, res;
		vc.push_back(0);
		for(int i = 0; i < n ; ++i){
			cin >> a;
			vc.push_back(a);
		}
		for(int i = 1; i <= n ; ++i){
			if(maxx < vc[i] - vc[i-1]){
				maxx = vc[i] - vc[i-1];
			}
		}

		res = maxx;
		for(int i = 1; i <= n; i++) {
            if(vc[i]-vc[i-1] == maxx)
                maxx--;
            else if(vc[i]-vc[i-1] > maxx) {
                res++;
                break;
            }
        }

		cout << "Case " << counter++ << ": " << res << endl;
		vc.clear();
	}
}
