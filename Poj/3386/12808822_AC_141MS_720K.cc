#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int A, a, B, b, P;
	cin >> A >> a >> B >> b >> P;

	if( A > B ){
		int tmp = A;
		A = B;
		B = tmp;
		tmp = a;
		a = b;
		b = tmp;
	}

	if( P >= A + B || (P >= B && b >= A) ){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}
