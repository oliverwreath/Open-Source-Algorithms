#include<iostream>
#include<string>

using namespace std ;

int main()
{
	char a[260] ;

	while( gets_s(a) )
	{
		if( a[0] == '#' ) return 0 ;
		int sum = 0 ;
		int length = (int)strlen(a) ;
		for( int i = 0 ; i < length ; i++ )
		{
			if( a[i] != ' ' )
				sum += (i+1) * (a[i]-64) ;
		}

		printf("%d\n", sum) ;
	}

    return 0 ;
}