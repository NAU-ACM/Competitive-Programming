#include <iostream>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	while (n--) {
		int a,b,c;
		bool done = false;
		cin >> a >> b >> c;
		for (int x=-22; !done && x<=22; x++) //x*x*x = B
			for (int y=x+1; !done && y<=100; y++)
				for (int z=y+1; !done && z<=100; z++)
					if ((x+y+z)==a && (x*y*z)==b && (x*x+y*y+z*z)==c) {
						cout << x <<" "<< y <<" "<< z << endl;
						done = true;						
						break;
					}
		if (!done)
			cout << "No solution." << endl;
	}
}