#include <iostream>

using namespace std;

int main()
{
	int S = 0, i = 1, sum = 0 ;
	cin >> S ;
	for ( i = 1 ; i <= 142 ; i++ )
	{
		sum += i ;
		if ( sum >= S && (sum - S) % 2 == 0 ) break ;
	}
	cout << i << endl ;
	return 0 ;
}