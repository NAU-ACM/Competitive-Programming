#include <iostream>
#include <iomanip>
using namespace std;
int m[201][201];

void BtoD (int Rl, int Rr, int Cl, int Cr, int ch) {
	// base case: 0-by-0 bitmap
	if (Rl == Rr || Cl == Cr) 
		return;

	// make each line 50 ch
	if (ch > 0 &&  ch%50 == 0)
		cout << endl;
	ch++;

	int zero=0;
    for (int r = Rl; r < Rr; ++r)
       	for (int c = Cl; c < Cr; ++c)
       			if (m[r][c] == 0) zero++;

    // if all are 0
    if (zero == (Rr-Rl)*(Cr-Cl))
    	cout << "0";
    // if all are 1
    else if (zero == 0)
    	cout << "1";
    // otherwise divide it
    else {

    	cout << "D";
    	// mid of R and C
    	int Rm = (Rl + Rr + 1) / 2;
    	int Cm = (Cl + Cr + 1) / 2;

    	// divide and conqure
    	BtoD(Rl, Rm, Cl, Cm, ch);
        BtoD(Rl, Rm, Cm, Cr, ch);
        BtoD(Rm, Rr, Cl, Cm, ch);
        BtoD(Rm, Rr, Cm, Cr, ch);
    }
}

void DtoB (int Rl, int Rr, int Cl, int Cr) {
	// base case: 0-by-0 bitmap	
	if (Rl == Rr || Cl == Cr)
    	return;

    // Get 1 char from cin.
    int ch = cin.get();

    // if all quarter is 0 or 1
    if (ch == '0' || ch == '1')
    {
        for (int r = Rl; r < Rr; ++r)
            for (int c = Cl; c < Cr; ++c)
                m[r][c] = ch - '0';
        return;
    }
    // otherwise extend quarters - divided part
    else
    {
        int Rm = (Rl + Rr + 1) / 2;
        int Cm = (Cl + Cr + 1) / 2;
    	DtoB(Rl, Rm, Cl, Cm);
        DtoB(Rl, Rm, Cm, Cr);
        DtoB(Rm, Rr, Cl, Cm);
        DtoB(Rm, Rr, Cm, Cr);
    }

}

int main () {
	char type;
	while (cin >> type, type != '#') {
		int row, col;
		cin >> row >> col;

		// print first line
		cout << (type == 'B'? "D" : "B") 
             << right << setw(4) << row  
             << right << setw(4) << col 
             << endl;

		if (type == 'B') {
			string s;
			// read all lines
    		while (s.size() < row * col)
    		{
        		string tmp;
        		getline(cin, tmp);
        		s = s + tmp;
    		}

    		// place to 2D map
    		for (int r = 0; r < row; ++r)
    	    	for (int c = 0; c < col; ++c)
        	    	m[r][c] = s[r * col + c] - '0';

			// start with entire map
			BtoD (0, row, 0, col, 0);
			cout << endl;
		}
		else {
			// start with entire map
			DtoB (0, row, 0, col);

			// print bit map
			for (int r = 0; r < row; ++r)
            	for (int c = 0; c < col; ++c)
                {
                    // make each line 50 char
                    if (r + c > 0 && (r * col + c) % 50 == 0)
                        cout << endl;
                    cout << m[r][c];
                }
            cout << endl;
        }	
	}
}