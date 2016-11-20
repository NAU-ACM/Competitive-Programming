#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
 
using namespace std;
bool used[104];
int main (){
	string s;
	int n;
	cin >> n;
	cin >> s;
	for (int i = 2; i < s.size(); ++i){
		if(s[i-2] == 'o' && s[i-1] == 'g' && s[i] == 'o'){
			int temp = i;
			int j = 0;
			while(s[i-1] == 'g' && s[i] == 'o'){
				i+=2;
				j+=2;
			}
			s.replace(temp-2,j+1,"***");
			i = temp;
		}
	}
	cout << s << endl;

}
