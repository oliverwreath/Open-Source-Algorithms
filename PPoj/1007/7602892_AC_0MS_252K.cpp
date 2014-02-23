

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std ;

typedef struct
{
	char a[60] ;
	int c ;
}stu ;

bool cmp( stu a, stu b )
{
	return ( a.c < b.c ) ;
}

int main()
{
	int n = 0 ;
	int m = 0 ;	
	
	//char a [110][60] = {0} ;
	//int c [110] = {0} ;
	stu ac [110] ;
	for( int i = 0 ; i < 110 ; i++ )
	{
		memset( ac[i].a, 0, sizeof(ac[i].a) ) ;
		ac[i].c = 0 ;
	}

	while( cin >> n >> m )
	{
		for( int i = 0 ; i < m ; i++ )
		{
			cin >> ac[i].a ;
		}
	
		for( int i = 0 ; i < m ; i++ )
		{
			for( int j = 0 ; j < n - 1 ; j++ )
			{
				for( int k = j + 1 ; k < n ; k++ )
				{
					if( ac[i].a[j] > ac[i].a[k] )
						ac[i].c ++ ;
				}
			}
		}

		sort( ac, ac+m, cmp ) ;

		//output
		for( int i = 0 ; i < m ; i++ )
		{
			cout << ac[i].a << endl ;
		}

	}

	return 0 ;
}
