#include<iostream>
#include<cmath>
#define MAX 65538
#define MIN -999

using namespace std; 

int main() 
{
	int t = 0 ;
	long long a[MAX]  = {0};
	long long i = 0 ;
	long long num = 0 ;

	a[1] = 1 ;

	for( i = 2 ; i < MAX ; i++ )
	{
		a[i] = a[i-1] + i-1 ;
	}


	cin >> t ;
	while( t-- )
	{
		cin >> num ;

		for( i = 1 ; i < MAX ; i++ )
		{
			if( a[i] >= num )
				if( a[i] == num )
				{
					cout << num << endl ;
					break ;
				}
				else 
				{
					cout << num - a[i-1]  + 1 << endl ;
					break ;
				}
		}
	}

	return 0 ;
}