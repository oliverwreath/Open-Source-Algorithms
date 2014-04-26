//============================================================================
// Name        : hello.cpp
// Author      : Oliver
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main(){
	long long l;
	int m;

	while( cin >> l >> m ){
		if( l == 0 && m == 0 )
			return 0;

		long long sum = 0;
		for( int i = 0; i < m; i++ ){
			long long left, right;
			cin >> left >> right;
			sum += right - left + 1;
		}

		cout << l+1-sum << endl;

	}

	return 0;
}
