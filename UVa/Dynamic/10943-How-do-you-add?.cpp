#include <iostream>
#include <cstring>
using namespace std;
int d[101][101];
int ways (int n, int k){

	if(d[n][k] != -1) return d[n][k];
	if (n == 1)	return d[n][k] = 1;

	int ans = 0;
	for(int i = 0 ; i <= n ; ++i)
		 ans = (ans % 1000000 +  ways(k-1, i) % 1000000) % 1000000;

    return d[n][k] = ans;

}

int main () {
	int n , k;
	cin >> n >> k;
	while(n && k){
		memset(d, -1 , sizeof(d));
		cout << ways(n, k) << endl;
		cin >> n >> k;
	}

}