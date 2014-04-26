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
	string strCoins1, strCoins2;
	string strStatus;
	int t;
	int * aryTracking;

	cin >> t;
	for( int i = 1; i <= t; i++ ){
		aryTracking = new int [12]();

		for( int r = 1; r <= 3; r++ ){
			cin >> strCoins1 >> strCoins2;
			cin >> strStatus;
			if( strStatus == "even" ){
				for( int j = 0; j < 4; j++ ){
					aryTracking[strCoins1[j]-'A'] = 10;
					aryTracking[strCoins2[j]-'A'] = 10;
				}
			}else{
				if( strStatus == "down" ){
					string tmp = strCoins1;
					strCoins1 = strCoins2;
					strCoins2 = tmp;
				}
				for( int j = 0; j < 4; j++ ){
					if( aryTracking[strCoins1[j]-'A'] == 0 )
						aryTracking[strCoins1[j]-'A'] = 11;
					if( aryTracking[strCoins1[j]-'A'] == 9 )
						aryTracking[strCoins1[j]-'A'] = 10;

					if( aryTracking[strCoins2[j]-'A'] == 0 )
						aryTracking[strCoins2[j]-'A'] = 9;
					if( aryTracking[strCoins2[j]-'A'] == 11 )
						aryTracking[strCoins2[j]-'A'] = 10;
				}
			}
		}

		for( int r = 0; r <= 11; r++ ){
			if( aryTracking[r] != 10 ){
				if( aryTracking[r] == 11 ){
					cout << static_cast<char>(r + 'A');
					cout << " is the counterfeit coin and it is " << "heavy" << "." << endl;
				}else if( aryTracking[r] == 9 ){
					cout << static_cast<char>(r + 'A');
					cout << " is the counterfeit coin and it is " << "light" << "." << endl;
				}
			}
		}

		delete [] aryTracking;
	}

	return 0;
}
