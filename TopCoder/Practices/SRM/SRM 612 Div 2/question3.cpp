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
 
class PowersOfTwo {
public:
	long long count(vector <long long> powers)
  	{
  		long long a[60];
  		for (int i = 0; i <= 50; ++i)
    		a[i] = 0;
  		long long Power[60];
  		Power[0]=1;
  		for (int i = 1; i <= 50; ++i)
    		Power[i] = Power[i - 1] * 2;
  		vector <long long>::iterator it;
  		for (it = powers.begin(); it < powers.end(); ++it)
    		for (int j = 0; j <= 50; ++j)
      			if (*it == Power[j]) ++a[j];
  		long long sum = 0;
  		for (int i = 0; i <= 50; ++i)
  		{
  			sum += Power[i] * a[i];
    		for (int j = i + 1; j <= 50; ++j)
    			if (sum >= Power[j])
      			{
        			a[i] += Power[j - i] * a[j];
        			sum += Power[j] * a[j];
        			a[j] = 0;
      			}
  		}
  		sum = 1;
  		for (int i = 0; i <= 50; ++i)
    		sum *= (a[i]  +1);
  		return sum;
	}
};
 
