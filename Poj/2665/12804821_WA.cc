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
	int l, m;
	int * dp;

	while( cin >> l >> m ){
		if( l == 0 && m == 0 )
			return 0;

		dp = new int [l+1]();
		for( int i = 0; i < m; i++ ){
			int left, right;
			cin >> left >> right;
			dp[left] = right - left + 1;
		}

		int sum = 0;
		int tmp = dp[0];
		for( int i = 1; i <= l; i++ ){
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
	}

	return 0;
}
