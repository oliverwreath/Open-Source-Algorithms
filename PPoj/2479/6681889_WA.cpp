#include<iostream>
#define MIN -1000000

using namespace std ;

int main()
{
	int t, n = 0 ;
	int a[50010] ;
	int dp[50010] ;

	scanf( "%d", &t ) ;

	while( t-- )
	{
		scanf( "%d", &n ) ;
		int ret = MIN ;
		int max = MIN ;
		int sum = 0 ;
		for( int i = 0 ; i < n ; i++ )
		{
			scanf( "%d", &a[i] ) ;
			sum += a[i] ;
			if( max < sum ) max = sum ;
			dp[i] = max ;
			if( sum < 0 ) sum = 0 ;
		}
		sum = 0 ;
		max = MIN ;
		for( int i = n - 1 ; i > -1 ; i-- )
		{
			sum += a[i] ;
			if( max < sum ) max = sum ;
			if( (dp[i-1] + max) > ret ) ret = dp[i-1] + max ;
			if( sum < 0 ) sum = 0 ;
		}
		cout << ret << endl ;
	}

    return 0 ;
}