#include<iostream>
#define MAXN 110
#define MIN -999

using namespace std; 

int main() 
{
	int n = 0 ;
	int a[MAXN][MAXN] = {0} ;
	int dp[MAXN][MAXN] = {0} ;

	while( cin >> n )
	{
		//input
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0  ; j < n ; j++ )
				cin >> a[i][j] ;

		//init sum of sub column
		for( int j = 0 ; j < n ; j++ )
			dp[0][j] = a[0][j] ;

		for( int j = 0  ; j < n ; j++ )
			for( int i = 1 ; i < n ; i++ )
				dp[i][j] = a[i][j] + dp[i-1][j] ;

		int max = MIN ;
		int sum = 0 ;
		
		for( int i1 = 1 ; i1 < n ; i1++ )
		{
			for( int i2 = i1 ; i2 < n ; i2++ )
			{
				sum = 0 ;
				for( int j = 0 ; j < n ; j++ )
				{
					sum += dp[i2][j] - dp[i1-1][j] ;
					if( sum > max )
						max = sum ;
					if( sum < 0 )
						sum = 0 ;
				}
			}
		}
		cout << max << endl ;
	}

	return 0 ;
}