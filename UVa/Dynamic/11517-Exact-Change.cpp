#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 10000
int t,W,n,c[101];
int dp[10005];

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &W, &n);
		for (int i=0; i<n; ++i)
			scanf ("%d", c+i);

		for (int i=0; i < INF; ++i)
            dp[i] = INF;
		dp[0] = 0;
		sort (c,c+n);
		for (int i=0; i < n; ++i)
			for (int j=INF; j >= 0; --j)
				if (j+c[i] <= INF && dp[j+c[i]] > dp[j]+1)
					dp[j+c[i]] = dp[j]+1;
				//dp[j] = min(dp[j], dp[j-c[i]]+1);
		for (int i=W; i <= INF; ++i)
			if (dp[i] != INF) {
				printf("%d %d\n", i, dp[i]);
				break;
			}
	}

}