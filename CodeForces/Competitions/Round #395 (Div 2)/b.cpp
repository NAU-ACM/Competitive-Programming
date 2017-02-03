#include <utility>
#include <iostream>
#include <vector>
using namespace std;

int main () {
	
	long n;
	cin >> n;
	long a[n+3];
	for(long i = 1; i <= n; ++i) cin >> a[i];
	bool ok = false;
	int left = 1, right = n;
	while (left <= right) {
		if (!ok) {
				swap(a[left], a[right]);
				ok = true;
			}
		else {
			ok = false;
		}
		left++, right--;
	}
	for(long i = 1; i <= n; ++i) cout << a[i] << ' ';
}