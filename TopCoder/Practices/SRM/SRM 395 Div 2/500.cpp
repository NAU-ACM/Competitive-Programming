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
#define ll long long
using namespace std;


class StreetWalking {
public:
	ll minTime(ll X, ll Y, ll walkTime, ll sneakTime) {
		ll diff = abs(X-Y), mn = min(X, Y);
		int rem = diff % 2;

		if(sneakTime < walkTime)			return ((mn+diff-rem)*sneakTime + rem*walkTime);	
		else if(walkTime * 2 > sneakTime)	return mn*sneakTime + diff*walkTime;
		else								return walkTime*(X+Y);
	}
};


<%:testing-code%>