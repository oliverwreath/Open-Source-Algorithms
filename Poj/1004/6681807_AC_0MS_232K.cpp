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

	int adjust = 0 ;
	adjust = ret * 1000 ;
	ret *= 100 ;
	if( adjust % 10 < 5 )		
		ret = (int)ret ;
	else
		ret = (int)(ret + 1) ;
	ret /= 1200 ;
	printf( "$%.2f", ret) ;

    return 0 ;
}