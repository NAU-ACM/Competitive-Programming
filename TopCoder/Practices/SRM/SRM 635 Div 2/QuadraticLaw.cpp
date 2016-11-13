// Gained: 403 points

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

class QuadraticLaw {
public:
	long long getTime(long long);
};

long long QuadraticLaw::getTime(long long d) {
	int i = 0;
	while(d >= i*(i+1)) i++;
	return --i;
}