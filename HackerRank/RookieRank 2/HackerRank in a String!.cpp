//@Author ATukenov

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string name, s;
int n, j;

int main() {
    cin >> n;
    name = "hackerrank";
    for (int q = 1; q <= n; ++q)
    {
        cin >> s;
        j = 0;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == name[j])
                j++;
        if (j >= name.size())
            printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
