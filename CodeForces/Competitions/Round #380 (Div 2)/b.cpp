#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
 
using namespace std;
int arr[1005][1005];
int main (){
	int n , m , res = 0;
	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> arr[i][j];

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; ++j){
			if(arr[i][j]){
				for(int k = i+1; k <= n; ++k)
					if(!arr[k][j] && k <= n)res++;
					else break;
				for(int k = i-1; k > 0; --k)
					if(!arr[k][j] && k > 0)res++;
					else break;
				for(int k = j+1; k <= m; ++k)
					if(!arr[i][k] && k <= m)res++;
					else break;
				for(int k = j-1; k > 0; --k)
					if(!arr[i][k] && k > 0)res++;
					else break;
			}
			
		}
	cout << res << endl;

}
