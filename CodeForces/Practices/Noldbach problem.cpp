#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector> // STL
#include <bitset> // STL
#include <map> // STL

using namespace std;

vector<int> primes;
map<int, int> m;
int n, k;

void check(){
	int res = 0;
	for(int i = 1; i < primes.size(); ++i)
		if(m[primes[i] + primes[i-1] + 1]) res++;
	if(res < k) cout << "NO\n";
	else cout << "YES\n";
}

void sieve(int size) {
	bitset<100010> was;
	was.set();      
	was[0] = was[1] = 0;
	for (int i = 2; i <= size; i++) 
  		if (was[i]) {
  			primes.push_back(i);
  			m[i] = 1;
	    	for (int j = i * i; j <= size; j += i) was[j] = 0;
  		}
  	check();
}

int main(){
	
	cin >> n >> k;
	sieve(n);

}