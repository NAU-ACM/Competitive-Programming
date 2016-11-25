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

class TaroString {
public:
	string getAnswer(string);
};

string TaroString::getAnswer(string S) {
	int a = 0, b = 0, c= 0;
	for(int i = 0; i < S.size() ; ++i){
		if(S[i] == 'C') a++;
		if(S[i] == 'A') b++;
		if(S[i] == 'T') c++;
	}
	if(a == 1 && b == 1 && c == 1) return "Possible";
	return "Impossible";
}