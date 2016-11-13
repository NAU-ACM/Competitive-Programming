#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm> 
#include <cmath>
using namespace std;
#define mod(a,b) sqrt(a*a-b*b)
#define INF 305
int n,m,S,c[41][2];
int dp[301][301];

int main () {
	scanf ("%d", &n);
	while (n--) {
		scanf ("%d %d", &m, &S);
		for (int i=0; i < m; ++i)
			scanf ("%d %d", &c[i][0], &c[i][1]);
		
		for (int i=0; i <= S; ++i)
			for (int j=0; j <= S; ++j)
				dp[i][j] = INF;
		dp[0][0] = 0;

		int ans = INF;
		for (int k=0; k < m; ++k)
			for (int i=c[k][0]; i <= S; ++i)
				for (int j=c[k][1]; j<=S; ++j) {
					dp[i][j] = min(dp[i][j], dp[i-c[k][0]][j-c[k][1]]+1);
					if (i*i + j*j == S*S)
						ans = min(ans, dp[i][j]);
				}
		if (ans == INF) printf("not possible\n");
		else printf("%d\n", ans);
	}
}