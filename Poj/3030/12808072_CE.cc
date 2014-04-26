#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;

	cin >> n;
	for( auto i = 0; i < n; i++ ){
		int r, e, c;
		cin >> r >> e >> c;
		e -= c + r;
		if( e > 0 ){
			cout << "advertise";
		}else if( e == 0 ){
			cout << "does not matter";
		}else{
			cout << "do not advertise";
		}

		cout << endl;
	}


	return 0;
}
