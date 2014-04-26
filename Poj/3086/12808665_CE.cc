#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int * T = new int [301];
	int * W = new int [301];

	//pre
	T[1] = 1;
	for( auto i = 2; i <= 300; i++ ){
		T[i] = T[i-1] + i;
	}

	W[1] = 3;
	for( auto i = 2; i <= 300; i++ ){
		W[i] = W[i-1] + i * T[i+1];
	}

	//body
	int t;
	cin >> t;
	int n;
	for( auto i = 1; i <= t; i++ ){
		cin >> n;
		cout << i << " " << n << " " << W[n] << endl;
	}

	//post
	delete [] T;
	delete [] W;

	return 0;
}
