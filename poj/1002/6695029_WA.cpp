#include<iostream>
#include<string>
#include<algorithm>

using namespace std ;

//bool cmp( int x, int y )
//{
//	return x > y ;
//}

int toInt( char b )
{
	switch(b)
	{
	case 'A':
	case 'B':
	case 'C':
		return 2 ;
	case 'D':
	case 'E':
	case 'F':
		return 3 ;
	case 'G':
	case 'H':
	case 'I':
		return 4 ;
	case 'J':
	case 'K':
	case 'L':
		return 5 ;
	case 'M':
	case 'N':
	case 'O':
		return 6 ;
	case 'P':
	case 'R':
	case 'S':
		return 7 ;
	case 'T':
	case 'U':
	case 'V':
		return 8 ;
	case 'W':
	case 'X':
	case 'Y':
		return 9 ;
	default :
		return b-'0' ;
	}
}


void trans( int * a, char * b )
{
	//*a = 0 ;
	for( int i = 0 ; i < (int)strlen(b) ; i++ )
	{
		if( b[i] != '-' )
		{
			*a += toInt( b[i] ) ;
			*a *= 10 ;
		}
	}
	*a /= 10 ;
}

int main()
{
	int n = 0 ;
	int a[100001] ;
	char b[30] ;

	cin >> n ;
	memset( a, 0, sizeof(a) ) ;

	for( int i = 0 ; i< n ; i++ )
	{
		scanf( "%s", b ) ;
		trans( &a[i], b ) ;
	}

	//for( int i = 0 ; i< n ; i++ )
	//{
	//	cout << a[i] << endl ;
	//}

	sort( a, a+n ) ;

	int ret = a[0] ;
	int count = 1 ;
	bool flag = false ;
	for( int i = 1 ; i < n ; i++ )
	{
		if( i == n-1 && count == 1 ) 
		{
				printf( "%03d-%04d %d\n", ret/10000, ret%10000, count+1 ) ;
				flag = true ;
				break ;
		}
		if( a[i] != ret )
		{
			if( count > 1 )
			{
				printf( "%03d-%04d %d\n", ret/10000, ret%10000, count ) ;
				flag = true ;
			}
			ret = a[i] ;
			count = 1 ;
		}else
		{
			count++ ;
		}
	}
	if( flag == false )
		printf( "No duplicates.\n" ) ;

	return 0 ;
}
