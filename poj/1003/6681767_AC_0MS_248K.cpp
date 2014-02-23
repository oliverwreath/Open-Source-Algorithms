#include<iostream>

using namespace std ;

int main()
{
	float c ;

	float a[276] ;
	a[0] = 0.5 ;
	for( int i = 1 ; i < 276 ; i++ )
		a[i] = a[i-1] + 1.0 /(i+2) ;

	while( cin >> c )
	{
		if( c == 0.0 ) return 0 ;
		int i = 0 ;
		while( a[i] < c )
		{
			i++ ;
		}
		cout << i + 1 << " card(s)" << endl ;
	}
    return 0 ;
}