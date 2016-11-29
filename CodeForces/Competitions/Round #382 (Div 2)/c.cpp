#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  long long n, x1 = 1, x2 = 1, step = 0;
  cin >> n;
  while(x1 <= n){
  	long long temp = x1;
    x1 = x1 + x2;
    x2 = temp;
    step++;
  }
  cout << --step << endl;
}