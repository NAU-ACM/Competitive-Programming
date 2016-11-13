/*
    Name: 10616 - Divisible Group Sums
    Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1557
    Topic: Dynamic
    Algo Used: Knapsack
*/
#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int n,q,d,m,a[300];
int dynamic[201][11][50];
int fun(int i,int c,int sum){

    if(c==m){
        if(sum) return 0;
        else return 1;
    }
    if(i>=n) return 0;
    if(dynamic[i][c][sum]!=-1) return dynamic[i][c][sum];

    return dynamic[i][c][sum]=fun(i+1,c+1,(sum+a[i])%d)+fun(i+1,c,sum);
}

int main () {

    int setCounter = 1;
    while ((cin >> n >> q) && n != 0 && q != 0) {

        printf("SET %d:\n", setCounter++);
        for(int i = 0 ; i < n ; ++i)
            cin >> a[i];
        
        for(int counter = 1 ; counter <= q ; ++counter){
            memset(dynamic,-1,sizeof(dynamic));
            cin >> d >> m;
            printf("QUERY %d: %d\n",counter+1,fun(0,0,0));
        }
        
    }

}