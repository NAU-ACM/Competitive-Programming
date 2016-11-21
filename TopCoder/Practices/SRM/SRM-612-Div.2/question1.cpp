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


class ImportantTasks {
public:
	int maximalCost(vector <int> complexity, vector <int> computers) {
		sort (complexity.begin(), complexity.end());
		sort (computers.begin(), computers.end());
		int l = complexity.size() - 1;
		int r = computers.size() - 1;
		int ans = 0;
		while (l >= 0 && r >= 0)
		{
			if (complexity[l] <= computers[r])
				ans++, l--, r--;
			else l--;		
		}
	}
};
