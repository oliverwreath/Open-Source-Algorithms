#include<iostream>
#include<algorithm>

using namespace std ;

int main()
{
	int t, n = 0 ;
	int a[20] ;

	scanf( "%d", &t ) ;

	while( t-- > 0 )
	{
		scanf( "%d", &n ) ;
		int sum = 0 ;
		for( int i = 0 ; i < n ; i++ )
			scanf( "%d", &a[i] ) ;

		sort( a, a + n ) ;

		printf("%d\n", 2*(a[n-1]-a[0])) ;
	}

    return 0 ;
}