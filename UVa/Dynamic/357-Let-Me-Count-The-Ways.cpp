#include <cstdio>
#include <cstring>
using namespace std;
int V, C = 5, coins[5] = {1,5,10,25,50};
long long int dp[6][31000];

long long int  ways (int type, int value) {
	if (value == 0)				return 1;
	if (value < 0 || type == C)	return 0;
	if (dp[type][value]!= -1)	return dp[type][value];
	return dp[type][value] = ways(type+1, value) + ways(type, value-coins[type]);
}

int main () {
	memset(dp, -1, sizeof dp);
	while (scanf("%d", &V) != EOF) {
		long long int w = ways(0, V);
		if (w == 1)
			printf("There is only 1 way to produce %d cents change.\n", V);
		else
			printf("There are %lld ways to produce %d cents change.\n", w, V);
	}

}