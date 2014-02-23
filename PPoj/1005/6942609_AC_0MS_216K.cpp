#include<iostream>

using namespace std;

int main()
{
	double x, y, ret = 0 ;
	int n = 0 ;
	double pi = 3.1415926535 ;
	int rett = 0 ;

	cin >> n ;
	for( int i = 1 ; i <= n ; i++ )
	{
		cin >> x >> y ;
		ret = ( x*x + y*y ) * pi / 100 ;
		rett = (int)( ret + 1 ) ;
		cout << "Property " << i << ": This property will begin eroding in year " << rett << "." << endl ;
	}
	cout << "END OF OUTPUT." << endl ;

	return 0 ;
}