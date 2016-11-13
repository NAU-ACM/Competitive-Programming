/*
    Name: 11790 - Murcia's Skyline
    Link: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2451
    Topic: Dynamic
    Algo Used: Longest Increasing Subsequence, Longest Decreasing Subsequence
*/
#include <iostream>
#include <vector>
using namespace std;
struct skys{ int w,h; };

int main (){

    int t, counter = 1, n;
    cin >> t;

    while(t--){
        cin >> n; // Number of elements
        int mx = 0, mx2 = 0, maxFirst = 0;

        skys dec[n+1], inc[n+1];
        skys a[n+1];

        for (int i = 0 ; i < n ; ++i){
            cin >> a[i].h;
            dec[i].h = inc[i].h = 1; // initializing the dynamic array
        }

        for (int i = 0 ; i < n ; ++i){
            cin >> inc[i].w;
            dec[i].w = inc[i].w;
            maxFirst = max(maxFirst, inc[i].w);
        }

        for (int i = 1 ; i < n ; ++i){
            int holder1 = 0, holder2 = 0;
            for (int j = 0 ; j < i ; ++j){
                if (a[i].h > a[j].h && inc[i].h <= inc[j].h+1){
                    inc[i].h = inc[j].h+1;
                    if(holder1 < inc[j].w)
                        holder1 = inc[j].w;
                }

                if (a[i].h < a[j].h && dec[i].h <= dec[j].h+1){
                    dec[i].h = dec[j].h+1;
                    if(holder2 < dec[j].w)
                        holder2 = dec[j].w;
                }
            }
            inc[i].w += holder1;
            dec[i].w += holder2;
        }

        int res = 0 , res2 = 0;

        for (int i = 0 ; i < n ; ++i){
            //cout << inc[i].w << " ";
            res = max(res, inc[i].w);
            res2 = max(res2, dec[i].w);
        }
        res = max(res, maxFirst);
        res2 = max(res2, maxFirst);

        if(res >= res2)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", counter++, res, res2);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", counter++, res2, res);
    }
}
