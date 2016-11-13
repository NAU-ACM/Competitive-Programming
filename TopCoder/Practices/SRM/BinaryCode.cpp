#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

class BinaryCode {
public:
	vector <string> decode(string);
};

vector <string> BinaryCode::decode(string message) {
	vector<string> vc;
	string s;
	int num1 = 0, num2, temp;
	bool ok = true;
	num2 = (message[0] - '0') - num1;
	s = to_string(num1);
	//cout << s << endl;
	s += to_string(num2);
	//cout << s << endl;
	if(num2 > 1 || num2 < 0 || num1 > 1 || num1 < 0 ) ok = false;
	for(int i = 1; i < message.size()-1 ; ++i){
		temp = num2;
		num2 = (message[i]-'0') - num1 - num2;
		//cout << num1 << endl;
		num1 = temp;
		//cout << num1 << " " <<(message[i]-'0')  << " " << temp<< endl;
		if(num2 > 1 || num2 < 0 || num1 > 1 || num1 < 0){
			ok = false;
			break;
		}
		s += to_string(num2);
		//cout << s << endl;
	}
	num2 = (message[message.size()-1]-'0') - num1 - num2;
	if(num2 > 1 || num2 < 0) ok = false;
	//cout << num2 << num1 << endl;
	if(ok) vc.push_back(s);
	else vc.push_back("NONE");
	ok = true;
	num1 = 1;
	num2 = (message[0] - '0') - num1;
	s = to_string(num1);
	s += to_string(num2);
	if(num2 > 1 || num2 < 0 || num1 > 1 || num1 < 0 ) ok = false;
	for(int i = 1; i < message.size()-1 ; ++i){
		temp = num2;
		num2 = (message[i]-'0') - num1 - num2;
		num1 = temp;
		if(num2 > 1 || num2 < 0 || num1 > 1 || num1 < 0){
			ok = false;
			break;
		}
		s += to_string(num2);
	}
	num2 = (message[message.size()-1]-'0') - num1 - num2;
	if(num2 > 1 || num2 < 0) ok = false;
	if(ok) vc.push_back(s);
	else vc.push_back("NONE");

	return vc;
}
