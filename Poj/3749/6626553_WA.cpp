#include <iostream>
#include <string>

using namespace std;

int main()
{
	char a[1000] ;
	while( gets_s(a) )
	{
		//逻辑处理
		if( strcmp( a, "ENDOFINPUT" ) == 0 ) break ;
		if( strcmp( a, "START" ) == 0 ) continue ;
		if( strcmp( a, "END" ) == 0 ) continue ;
		//转换函数
		for( unsigned int i = 0 ; i < strlen(a) ; i++ )
		{
			int asc = (int)a[i] ;
			if( asc >= 65 && asc <= 90 ) 
			{
				asc = ( asc - 64 - 5 + 26 ) % 26 + 64 ;
				a[i] = (char)asc ;
			}
			else 
				continue ;
		}
		cout << a << endl ;
	}
	return 0 ;
} 