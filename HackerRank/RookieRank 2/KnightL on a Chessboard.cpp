#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans[26][26], used[26][26], way;
struct qwe {
    int x, y;
} q[1001];

int bfs(int a, int b) {
    int start = 1, finish = 1;
    q[start].x = 0;
    q[start].y = 0;
    while (start <= finish) {
        int X = q[start].x;
        int Y = q[start].y;
        if (X + a < n && Y + b < n && !used[X + a][Y + b])
            used[X + a][Y + b] = used[X][Y] + 1, finish++, q[finish].x = X + a, q[finish].y = Y + b;
        if (X + a < n && Y - b > -1 && !used[X + a][Y - b])
            used[X + a][Y - b] = used[X][Y] + 1, finish++, q[finish].x = X + a, q[finish].y = Y - b;
        if (X - a > -1 && Y + b < n && !used[X - a][Y + b])
            used[X - a][Y + b] = used[X][Y] + 1, finish++, q[finish].x = X - a, q[finish].y = Y + b;
        if (X - a > -1 && Y - b > -1 && !used[X - a][Y - b])
            used[X - a][Y - b] = used[X][Y] + 1, finish++, q[finish].x = X - a, q[finish].y = Y - b;
        if (X + b < n && Y + a < n && !used[X + b][Y + a])
            used[X + b][Y + a] = used[X][Y] + 1, finish++, q[finish].x = X + b, q[finish].y = Y + a;
        if (X + b < n && Y - a > -1 && !used[X + b][Y - a])
            used[X + b][Y - a] = used[X][Y] + 1, finish++, q[finish].x = X + b, q[finish].y = Y - a;
        if (X - b > -1 && Y + a < n && !used[X - b][Y + a])
            used[X - b][Y + a] = used[X][Y] + 1, finish++, q[finish].x = X - b, q[finish].y = Y + a;
        if (X - b > -1 && Y - a > -1 && !used[X - b][Y - a])
            used[X - b][Y - a] = used[X][Y] + 1, finish++, q[finish].x = X - b, q[finish].y = Y - a;
        start++;
        if (used[n - 1][n - 1])
            return used[n - 1][n - 1];
    }
    return -1;
}

int main() {
    cin >> n;
    for (int a = 1; a < n; a++)
        for (int b = a; b < n; ++b) {
            way = bfs(a, b);
            ans[a][b] = ans[b][a] = way;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    used[i][j] = 0;
        }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
