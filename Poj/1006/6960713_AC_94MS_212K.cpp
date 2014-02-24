#include<iostream>

using namespace std;

int main()
{
	int p, e, i, d = 0 ;
	int k = 1 ;

	while( cin >> p >> e >> i >> d )
	{
		int ret = 0 ;
		if( p == e && e == i && i == d && d == -1 )
			break ;

		p %= 23 ;
		e %= 28 ;
		i %= 33 ;
		
		for( int j = i ;  ; j += 33 )
		{
			if( j % 23 == p && j % 28 == e )
			{
				ret = j ;
				break ;
			}
		}

		if( ret > d )
			ret = ret - d ;
		else if( ret == d )
			ret = ret + 21252 ;
		else 
			ret = ret + 21252 - d ;
		
		cout << "Case " << k++ << ": the next triple peak occurs in " << ret << " days." << endl ;
		
	}

	return 0 ;
}