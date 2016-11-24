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


class GridSort {
public:
	string sort(int n, int m, vector <int> grid) {
		int N = n * m;
		int sum = 0;
		int c[m + m];
		for (int i = 0; i <= m; ++i)
			c[i] = 0;
		map <int, bool> was;
		for (int i = 1; i <= N; ++i)
		{
			sum += i;
			if (i % m == 0)
				was[sum] = true, sum = 0;
			c[i % m] += i;
		}
		map <int, bool> was1;
		for (int i = 0; i < m; ++i)
			was1[c[i]] = true;
		for (int i = 0; i < n; ++i)
		{
			sum = 0;
			for (int j = 0; j < m; ++j)
				sum += grid[i * m + j];
			if (!was[sum])
				return "Impossible";
		}
		for (int i = 0; i < m; ++i)
		{
			sum = 0;
			for (int j = 0; j < n; ++j)
				sum += grid[j * m + i];
			if (!was1[sum])
				return "Impossible";
		}
			
		return "Possible";	
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
