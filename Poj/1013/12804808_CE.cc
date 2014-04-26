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

		for( auto r = 1; r <= 3; r++ ){
			cin >> strCoins1 >> strCoins2;
			cin >> strStatus;
			if( strStatus == "even" ){
				for( auto j = 0; j < 4; j++ ){
					aryTracking[strCoins1[j]-'A'] = 10;
					aryTracking[strCoins2[j]-'A'] = 10;
				}
			}else if( strStatus == "up" ){
				for( auto j = 0; j < 4; j++ ){
					if( aryTracking[strCoins1[j]-'A'] != 10 )
						aryTracking[strCoins1[j]-'A'] = 11;
					if( aryTracking[strCoins2[j]-'A'] != 10 )
						aryTracking[strCoins2[j]-'A'] = 9;
				}
			}else{
				for( auto j = 0; j < 4; j++ ){
					if( aryTracking[strCoins1[j]-'A'] != 10 )
						aryTracking[strCoins1[j]-'A'] = 9;
					if( aryTracking[strCoins2[j]-'A'] != 10 )
						aryTracking[strCoins2[j]-'A'] = 11;
				}
			}
		}

		for( auto r = 0; r <= 11; r++ ){
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
