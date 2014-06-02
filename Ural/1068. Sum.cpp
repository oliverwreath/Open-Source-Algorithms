#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cmath>
#include <stack>

using namespace std;

void Sum(int n){
	if( n == 0 ){
		cout << 1 << endl;
	}else if( n < 0 ){
		cout << abs(n)* (n-1)/ 2 + 1 << endl;
	}else{
		cout << (n+1)* n/ 2 << endl;
	}
}

int main(){
	int n;
	while(cin >> n){
		Sum(n);
	}

	return 0;
}
