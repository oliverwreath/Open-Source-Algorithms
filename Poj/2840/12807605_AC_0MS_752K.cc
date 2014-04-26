#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	string str;

	cin >> t;
	getline( cin, str );
	for( int i = 0; i < t; i++ ){
		getline( cin, str );

		int ret;
		if( str[1] == ':' ){
			//one bit hour
			int hour = str[0] - '0';
			if( str[2] != '0' || str[3] != '0' ){
				ret = 0;
			}else{
				ret = hour + 12;
			}
		}else if( str[2] == ':' ){
			//two bit hour
			if( str[3] != '0' || str[4] != '0' ){
				ret = 0;
			}else{
				int hour = (str[0] - '0') * 10 + (str[1] - '0');
				if( hour < 13 ){
					ret = hour + 12;
				}else{
					ret = hour - 12;
				}
			}
		}

		cout << ret << endl;
	}

	return 0;
}
