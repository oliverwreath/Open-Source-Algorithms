#include <iostream>
//#include <string>
//#include <cmath>

using namespace std ;

int main()
{
	int n = 0 ;
	int a[10000] ;
	int sum = 0 ;

	//输入
	cin >> n ;
	for( int i = 0 ; i < n ; i++ )
		cin >> a[i] ;

	for( int i = 0 ; i < n ; i++ )
	{
		for( int j = 0 ; j < n ; j++ )
			sum += abs( a[i] - a[j] ) ;
	}

	cout << sum << endl ;

	return 0 ;
}

