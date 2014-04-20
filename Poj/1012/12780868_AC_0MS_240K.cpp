#include <iostream>

using namespace std; 

int main(){
	int k = 1;
	int dp[14] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};

	while( cin >> k ){
		if( k == 0 ) break;
		
		cout << dp[k] << endl;
	}

	return 0;
}
