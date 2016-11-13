/*
    Name: 11456 - Trainsorting
    Link: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2451
    Topic: Dynamic
    Algo Used: Longest Increasing Subsequence
*/
#include <iostream>
using namespace std;
int a[2500], d[2500],  in[2500];
int main ()
{
    int n , t;
    cin >> t;
    while(t--){
        cin >> n; // Number of elements
        int mx = 0;

        for (int i = 0 ; i < n ; ++i){
            cin >> a[i];
            d[i] = in[i] = 1; // initializing the dynamic arrays
        }

        for (int i = n-1 ; i >= 0 ; --i)
            for (int j = i+1 ; j < n ; ++j)
                if (a[i] > a[j] && in[i] < in[j]+1 )
                    in[i] = in[j]+1;

        for (int i = n-1 ; i >= 0 ; --i)
            for (int j = i+1 ; j < n ; ++j)
                if (a[i] < a[j] && d[i] < d[j]+1 )
                    d[i] = d[j]+1;

        for (int i = 0 ; i < n ; ++i)
            mx = max(mx, in[i] + d[i] - 1);

        cout << mx << endl;
    }
	return 0;
}
