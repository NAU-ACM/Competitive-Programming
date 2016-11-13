// /*
//     Name: 11566 - Let's Yum Cha!
//     Link: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2613
//     Topic: Dynamic
//     Algo Used: Knapsack
// */
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
int v[101], f[111], d[111], c[111], m[111], N, x, T, K, max_X;;
bool was[111];

int main () {

	cin >> N >> x >> T >> K;

	while(N && x && T && K){
	
		max_X = x * (N+1); // IMPORTANT
		for(int i = 1 ; i <= K ; ++i){
			int sum = 0 , a;
			cin >> v[i];
			m[i] = v[i];
			for(int j = 1; j <= N+1 ; ++j){
				cin >> a;
				sum += a;
			}
			f[i] = sum / (N+1);
		}

		memset(was, 0, sizeof was);
		memset(d, 0, sizeof d);
		memset(c, 0, sizeof c);

		was[0] = true;

		for(int i = 1 ; i <= K ; ++i){
			for (int j = max_X ; j >= 0 ; --j){
				if(was[j]){
					was[j + v[i]] = true;
					if(d[j] + f[i] > d[j + v[i]]){
						d[j + v[i]] = d[j] + f[i];
						m[j + v[i]] = m[j] + m[i];
						c[j + v[i]] = c[j] + 1;
					}
				}
			}
		}

		for(int i = 0 ; i < max_X ; i++)
			cout << d[i] << " " ;
		cout << endl;
		for(int i = 0 ; i < max_X ; i++)
			cout << c[i] << " " ;
		cout << endl;
		for(int i = 0 ; i < max_X ; i++)
			cout << m[i] << " " ;
		cout << endl;

		double sum = 0;
		for (int i = 0; i <= max_X; ++i)
			if (c[i] <= 2*N+2 && max_X >= ( ceil(m[i]*110/100) - T*(N+1)))
				sum = max((int)sum, d[i]);

		printf("%.2f\n", sum/(N+1));
		cin >> N >> x >> T >> K;
	}

}
