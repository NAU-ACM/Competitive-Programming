#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

class SquareDigitNumbers{
public:
	bool lookAtDigits(int x){
		while(x >= 1){
			int rem = x%10;
			if(!(rem == 0 | rem == 1 | rem == 4 | rem == 9)) return false;
			x /= 10;
		}
		return true;
	}
	
	int getNumber(int n) {
		vector<int> vc;
		for (int i  = 0; i < 999999; ++i)  
			if(lookAtDigits(i)) vc.push_back(i);
		return vc[n];
	}
};


<%:testing-code%>