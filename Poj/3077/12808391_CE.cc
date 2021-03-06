#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	string str;
	cin >> t;

	for( int r = 0; r < t; r++ ){
		getline(cin, str);
		int len = str.length();
		for( auto &ch : str ){
			ch -= '0';
		}

		for( auto i = len-1; i > 0; i-- ){
			if( str[i] > 4 ){
				//add 1 carry
				str[i-1] += 1;
			}
			str[i] = 0;
		}

		if( str[0] > 9 ){
			cout << str[0] / 10;
			str[0] %= 10;
		}

		for( auto &ch : str ){
			ch += '0';
		}

		cout << str << endl;
	}

	return 0;
}
