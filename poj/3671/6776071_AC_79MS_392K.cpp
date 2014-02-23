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
		int ret = n ;
		for( int i = 0 ; i < n ; i++ )
			cin >> a[i] ;

		//memset( dp, 0001, sizeof(dp) ) ;
		for( int i = 0 ; i < n ; i++ )
			dp[i] = 0 ;

		bool flag = false ;
		bool flag2 = false ;
		int count = 0 ;
		for( int i = 0 ; i < n ; i++ )
			if( a[i] == 2 )
			{
				count++ ;
				flag2 = true ;
			}
			else
			{
				dp[i] = count ;
				flag = true ;
			}

		if( flag == false || flag2 == false )
		{
			cout << 0 << endl ;
			continue ;
		}

		count = 0 ;
		for( int i = n-1 ; i >= 0 ; i-- )
			if( a[i] == 1 )
			{
				dp[i] += count++ ;
				if( dp[i] < ret )
					ret = dp[i] ;
			}

		cout << ret << endl ;

	}
}