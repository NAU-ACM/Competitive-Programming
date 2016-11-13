//Talgat Yegizbayev
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int t,t2,t3,i,j;
	int min1[10001],max1[10001],price;
	int help=0;
	string s1[10001];
	cin>>t;

	while( t-- )
	{
		cin >>t2;
		for ( i=0; i<t2; i++ )
			cin>>s1[i]>>min1[i]>>max1[i];
		cin >>t3;
		while ( t3-- )
		{
			cin>>price;
			for ( i=0; i<t2; i++ )
			{
				if ( min1[i]<=price && price<=max1[i] )
				{
					help++; j=i;
					if ( help > 1 )
						break;
				}
			}
			if ( help == 1 )
				cout<< s1[j] <<endl;
			else
				cout<<"UNDETERMINED"<<endl;
			help=0;
		}
		if(t) cout<<endl;
	}
	return 0;
}
