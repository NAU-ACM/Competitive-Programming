#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class TaroFriends {
public:
	int getNumber(vector <int>, int);
};

int TaroFriends::getNumber(vector <int> vc, int x) {
	sort(vc.begin(), vc.end());
	vector<int> v;
	for(int i = 0 ; i < vc.size() ; ++i) vc[i] -= x;
	int res = vc[vc.size()-1] - vc[0];
	for(int i = 0 ; i < vc.size() ; ++i){
		vc[i] += 2*x;
		for(int j = 0; j < vc.size() ; ++j) v.push_back(vc[j]);
		sort(v.begin(), v.end());
		res = min(res, v[v.size()-1] - v[0]);
		v.clear();
	}
	return res;
}