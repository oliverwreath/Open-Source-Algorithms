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
	int * dp;

	while( cin >> l >> m ){
		if( l == 0 && m == 0 )
			return 0;

		dp = new long long [l+1]();
		for( int i = 0; i < m; i++ ){
			long long left, right;
			cin >> left >> right;
			dp[left] = right - left + 1;
		}

		long long sum = 0;
		long long tmp = dp[0];
		for( long long i = 1; i <= l; i++ ){
			if( tmp > 0 ){
				sum++;
				tmp--;
			}
			if( dp[i] > 0 ){
				tmp = tmp>dp[i]?tmp:dp[i];
			}
		}

		if( tmp > 0 ){
			sum++;
			tmp--;
		}

		cout << l+1-sum << endl;

		delete [] dp;
	}

	return 0;
}
