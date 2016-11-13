/*
    Name: 11236 - Grocery store
    Link: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2177
    Topic: Complete Search
    Algo Used: -
*/
#include <iostream>
#include <cmath>
#define tenSix 1000000
using namespace std;

int main (){
    for (int i = 1; 4*i <= 2000; ++i)
        for (int j = i; 3*j+i <= 2000; ++j)
            for (int k = j; 2*k+i+j <= 2000; ++k) {

                int a = i*j*k;
                int b = i+j+k;

                if(a <= tenSix) continue;

                int d = (b * tenSix)/(a - tenSix);

                if(d >= k && b+d <= 2000 && (b * tenSix)%(a - tenSix) == 0 && fabs((b + d) / 100.0 - (a * d) / 100000000.0) < tenSix*2000)
                    printf("%.2f %.2f %.2f %.2f\n", i/100.0, j/100.0, k/100.0, d/100.0);
            }
}
