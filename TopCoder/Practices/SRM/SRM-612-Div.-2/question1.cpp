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


class LeftAndRightHandedDiv2 {
public:
	int count(string S) {
		int ans = 0;
		for (int i = 0; i < S.size() - 1; ++i)
			if (S[i] == 'R' && S[i + 1] == 'L')
				ans++;
		return ans;	
	}
};
