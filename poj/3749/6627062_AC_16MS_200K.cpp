#include <iostream>
#include <string>

using namespace std;

int main()
{
	char a[201] ;
	string command ;

	cin >> command ;

	while( 1 )
	{
		//逻辑处理
		if( command == "ENDOFINPUT" ) break ;
		if( command == "END" )
		{
			cin >> command ;
			continue ;
		}
		if( command == "START" ) 
		{
			cin.getline( a, 201 ) ;
			cin.getline( a, 201 ) ;

			//转换函数
			for( unsigned int i = 0 ; i < strlen(a) ; i++ )
			{
				int asc = (int)a[i] ;
				if( asc >= 65 && asc <= 90 ) 
				{
					asc = ( asc - 44 ) % 26 + 65 ;
					a[i] = (char)asc ;
				}
				else 
					continue ;
			}
			cin >> command ;

			cout << a << endl ;

			continue ;
		}
	}
	return 0 ;
} 