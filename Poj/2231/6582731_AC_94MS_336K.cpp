#include <iostream>
//#include <string>
//#include <cmath>
#include <algorithm>

using namespace std ;

int main()
{
	int n = 0 ;
	long long a[10000] ;
	long long sum = 0 ;

	
	while( cin >> n )
	{
		//初始化
		sum = 0 ;
		//输入
		for( int i = 0 ; i < n ; i++ )
			cin >> a[i] ;

		//排序
		sort(a, a+n) ;

		//未优化算法
		//for( int i = 0 ; i < n ; i++ )
		//{
		//	for( int j = 0 ; j < n ; j++ )
		//		sum += abs( a[i] - a[j] ) ;
		//}
		for( int i = 1 ; i < n ; i++ )
		{
			sum += 2 * ( a[i] - a[i - 1] ) * i * (n - i) ;
		}

		cout << sum << endl ;
	}

	return 0 ;
}

