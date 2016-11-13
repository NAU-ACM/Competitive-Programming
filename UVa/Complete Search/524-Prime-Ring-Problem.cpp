#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;
int primes[11] = {2,3,5,7,11,13,17,19,23,29,31}; 	// max=15+16
bitset<20> used;
int cycle[20];
int n;

bool isPrime (int num) {
	for (int i=0; i<11; ++i)
		if (num == primes[i]) 
			return true;
	return false;
}

bool place (int pos, int x) {
	if (pos != n-1) {
		if (isPrime(cycle[pos-1]+x)) 
			return true;
		else 
			return false;
	}
	else {
		if (isPrime(cycle[pos-1]+x) && isPrime(x+cycle[0]))
			return true;
		else 
			return false;
	}
}

void backtrack (int k) {
	if (k == n) {
		for (int i=0; i < n; ++i)
			printf ("%d ", cycle[i]);
		printf("\n");
		return;
	}
	for (int i=2; i <= n; ++i) {
		if (!used[i] && place(k,i)) {
			cycle[k] = i;
			used[i] = true;
			backtrack(k+1);
			used[i] = false;
		}
	}
}

int main () {
	int c=1;
	while (scanf("%d", &n) == 1) {
		printf("Case %d\n", c++);
		cycle[0] = 1;
		used[0] = true;
		backtrack(1);
		printf("\n");
	}

}