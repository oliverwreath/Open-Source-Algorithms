#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main(){
	int N, L;
	int * trees;
	int INT_MAX = numeric_limits<int>::max();

	while( cin >> N >> L ){
		trees = new int [N+3]();

		for( int i = 0; i < N; i++ ){
			cin >> trees[i];
		}

		int minTax = INT_MAX;
		int ret = 0;
		for( int t = 0; t <= L; t++ ){
			int tax = 0;

			for( int i = 0; i < N; i++ ){
				tax += trees[i]%L;
			}
			if( tax < minTax ){
				minTax = tax;
				ret = t;
			}

			for( int i = 0; i < N; i++ ){
				trees[i]++;
			}
		}

		cout << ret << endl;
	}

	return 0;
}
