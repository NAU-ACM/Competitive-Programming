// Gained: 238 points

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

class IdentifyingWood {
public:
	string check(string, string);
};

string IdentifyingWood::check(string s, string t) {
	int i = 0;
	for(int j =0; j < s.size() && t.size() != 0 ; ++j){
		if(s[j] == t[0]){
			t.erase(0, 1);
			//cout << t << endl;
		}
	}
	if(t.size() == 0) return "Yep, it's wood.";
	else return "Nope.";
}