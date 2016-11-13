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

class OrderedNim {
public:
	string winner(vector <int>);
};

string OrderedNim::winner(vector <int> layout) {
	for(vector<int>::iterator it = layout.begin(); it != layout.end()-1; ++it){
		if(*it >= 2){
			return "Alice";
		} 
	}
	(layout.size() == 1) return "Alice";
	return "Bob";
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!