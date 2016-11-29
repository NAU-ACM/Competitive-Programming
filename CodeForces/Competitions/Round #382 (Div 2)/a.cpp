#include <iostream>

using namespace std;

int main () {

  int n , k, G, T;
  string s;
  cin >> n >> k;
  cin >> s;
  for(int i =0 ; i < s.size() ; ++i){
    if(s[i] == 'G'){
      G = i;
    }
    else if(s[i] == 'T'){
      T = i;
    }
  }
  if(T < G){
    int temp = T;
    T = G;
    G = temp;
  }
  int i;
  for( i = G ; i <= T ; i+=k){
    if(s[i] == '#'){
      cout << "NO" << endl;
      exit(0);
    }
  } 
  if(i == T+k)cout << "YES" << endl;
  else cout << "NO" << endl;
}