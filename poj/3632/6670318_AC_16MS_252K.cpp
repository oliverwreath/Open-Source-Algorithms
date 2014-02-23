#include<iostream>
#include<algorithm>

using namespace std ;

int main()
{
	int t, n = 0 ;
	int a[20] ;
	cin >> t ;
	while( t-- > 0 )
	{
		cin >> n ;
		int sum = 0 ;
		for( int i = 0 ; i < n ; i++ )
			cin >> a[i] ;
		sort( a, a + n ) ;
		cout << 2*(a[n-1]-a[0]) << endl ;
	}

    return 0 ;
}