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

class LeftAndRightHandedDiv2 {
public:
	int count(string);
};

int LeftAndRightHandedDiv2::count(string S) {
	int res = 0;
	for(int i = 0; i < S.size() ; ++i){
		if(S[i] == 'R' && S[i+1] == 'L'){
			res++;
			int temp = i;
			S.erase(i,2);
			i = temp;
		}
		else if(S[i] == 'L' && S[i-1] == 'R' && i >= 1){
			res++;
			int temp = i-1;
			S.erase(i-1,2);
			i = temp;
		}
	}
	return res;
}