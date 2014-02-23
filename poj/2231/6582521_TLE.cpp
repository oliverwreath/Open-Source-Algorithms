#include <iostream>
//#include <string>
//#include <cmath>

using namespace std ;

int main()
{
	int n = 0 ;
	long long a[10000] ;
	long long sum = 0 ;

	//输入
	while( cin >> n )
	{
		sum = 0 ;
		for( int i = 0 ; i < n ; i++ )
			cin >> a[i] ;

		for( int i = 0 ; i < n ; i++ )
		{
			for( int j = 0 ; j < n ; j++ )
				sum += abs( a[i] - a[j] ) ;
		}

		cout << sum << endl ;
	}

	return 0 ;
}

