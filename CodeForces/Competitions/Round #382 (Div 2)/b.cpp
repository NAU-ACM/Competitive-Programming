#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

	int n , n1, n2, a;
  vector<int> vc;
  cin >> n >> n1 >> n2;
  for(int i = 0; i < n ; ++i){
    cin >> a;
    vc.push_back(a);
  } 
  sort(vc.begin() , vc.end());
  reverse(vc.begin(), vc.end());
  int mn = min(n1, n2);
  int mx = max(n1, n2);
  double sum1 = 0, sum2 = 0;
  for(int i = 0; i < mn ; ++i){
    sum1 += vc[i];
  }
  for(int i = mn; i < mx+mn ; ++i){
    sum2 += vc[i];
  }
  printf("%.6f", sum1/mn + sum2/mx);
  return 0;

}