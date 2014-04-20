#include <iostream>

using namespace std; 

int main(){
	int k = 1;
	int dp[] = new int [14]();

	while( cin >> k ){
		if( k == 0 ) break;
		if( dp[k] > 0 ){
			cout << dp[] << endl;
			continue; 
		}

		int m = k+1;

		while( true ){
			bool flag = true;
			int size = 2 * k;
			int deadNum = m % size;
			int offSet = 0;
			for( int i = 1; i <= k; i++ ){
				deadNum += offSet;
				if( deadNum < 1 ) deadNum += size;
				//cout << " k ->" << deadNum << "/" << size;
				if( deadNum <= k && deadNum > 0 ){
					flag = false;
					m++;
					break;
				}else{
					offSet = deadNum - size;
					size--;
					deadNum = m % size;
				}
			}

			if( flag ){
				break;
			}
		}
		
		dp[k] = m;
		cout << dp[k] << endl; 
	}

	return 0;
}