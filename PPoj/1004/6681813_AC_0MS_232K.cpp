#include<iostream>

using namespace std ;

int main()
{
	float ret = 0.0 ;
	float a = 0.0 ;

	for( int i = 1 ; i <= 12 ; i++ )
	{
		cin >> a ;
		ret += a ;
	}

	printf( "$%.2f", ret / 12 ) ;

    return 0 ;
}