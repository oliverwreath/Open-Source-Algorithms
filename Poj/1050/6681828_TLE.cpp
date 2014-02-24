#include<iostream>

using namespace std ;

int main()
{
	int n = 0 ;
	int a[101][101] ;

	while( cin >> n )
	{
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < n ; j++ )
				cin >> a[i][j] ;

		int max = 0 ;
		for( int i = 0 ; i < n-1 ; i++ )
			for( int j = 0 ; j < n-1 ; j++ )
				for( int m = i+1 ; m < n ; m++ )
					for( int k = j+1 ; k < n ; k++ )
					{
						int sum = 0 ;
						for( int l = i ; l <= m ; l++ )
							for( int d = j ; d <= k ; d++ )
								sum += a[l][d] ;
						if( sum > max )
							max = sum ;
					}
		cout << max << endl ;


	}

    return 0 ;
}