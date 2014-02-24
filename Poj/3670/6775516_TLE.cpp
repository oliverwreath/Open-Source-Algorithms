#include<iostream>
#include<cstring>
//#define MAX 65538
#define MAX 75538

#define length 30001

using namespace std; 

int max( int x, int y )
{
	if( x > y )
		return x ;
	else 
		return y ;
}

int main() 
{
	int n = 0 ;
	short a[length] = {0} ;
	int dp[length] = {0} ;

	while( cin >> n )
	{
		for( int i = 0 ; i < n ; i++ )
			cin >> a[i] ;

		memset( a, -1, sizeof(a) ) ;
		int maxL = 1 ;
		for( int i = 1 ; i < n ; i++ )
		{
			for( int j = 0 ; j < i ; j++ )
			{
				if( a[j] >= a[i] )
					dp[i] = max( dp[j]+1, dp[i] ) ;
			}
			if( maxL < dp[i] )
				maxL = dp[i] ;
		} 

		memset( a, -1, sizeof(a) ) ;
		for( int i = 1 ; i < n ; i++ )
		{
			for( int j = 0 ; j < i ; j++ )
			{
				if( a[j] >= a[i] )
					dp[i] = max( dp[j]+1, dp[i] ) ;
			}
			if( maxL < dp[i] )
				maxL = dp[i] ;
		} 

		cout << n - maxL << endl ;

	}
}