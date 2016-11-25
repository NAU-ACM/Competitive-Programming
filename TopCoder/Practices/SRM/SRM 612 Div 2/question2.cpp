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


class EmoticonsDiv2 {
public:
	int printSmiles(int smiles) {
		int ans = smiles;
		for (int x = 1; x < smiles; ++x)
			if (smiles % x == 0)
				ans = min(ans, printSmiles(x) + smiles / x);
	return ans;
	}
};
