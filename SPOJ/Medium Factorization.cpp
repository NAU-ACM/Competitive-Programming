#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector> // STL
#include <bitset> // STL
#define mxNum 10000007
using namespace std;
vector<int> was(mxNum, 0);
void sieve(){
	was[0] = was[1] = 1;
	for (int i = 2; i*i <= was.size(); i++) 
  		if (!was[i])
	    	for (int j = i*i; j <= was.size(); j += i)
	    		if(!was[j]) was[j] = i;
}

void primeFactors(int N){
	cout << "1 x" ;
	while(was[N] != 0 && N % was[N] == 0){
		printf(" %d x", was[N]);
		if(was[N] == 0) break;
		N /= was[N];
	}
	printf(" %d\n", N);
}

int main(){
	
	sieve();
	int n;
	while(scanf("%d", &n) == 1)
		if(n == 1){
			printf("1\n");
			continue;
		}
		else primeFactors(n);
	
}
