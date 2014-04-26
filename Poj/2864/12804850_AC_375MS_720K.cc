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
	int n, d;
	int * dp;

	while( cin >> n >> d && n != 0 && d != 0 ){
		dp = new int [n]();
		int tmp;

		for( int i = 1; i <= d; i++ ){
			for( int j = 0; j < n; j++ ){
				cin >> tmp;
				if( tmp == 0 ){
					dp[j] = 1;
				}
			}
		}

		bool flag = false;
		for( int j = 0; j < n; j++ ){
			if( dp[j] == 0 ){
				flag = true;
				break;
			}
		}

		if( flag ){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}

		delete [] dp;
	}

	return 0;
}
