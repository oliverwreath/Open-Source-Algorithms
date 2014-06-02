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
#include <set>

using namespace std;

class Solution{
	set<unsigned int> dp;
	const unsigned int LENGTH_OF_DP = 2147483647;

public:
	void init(){
		unsigned int i = 1, step = 1;
		while( i < LENGTH_OF_DP ){
			dp.insert(i);
			i += step;
			step++;
		}

		return;
	}

	int get110100(int n){
		return (dp.find(n)==dp.end()?0:1);
	}
};


int main(){
	int n;
	Solution t = Solution();
	t.init();
//	assert(t.get110100(1) == 1);
//	assert(t.get110100(2) == 1);
//	assert(t.get110100(3) == 0);
//	assert(t.get110100(4) == 1);
//	assert(t.get110100(5) == 0);
//	assert(t.get110100(6) == 0);
//	assert(t.get110100(7) == 1);
//	assert(t.get110100(8) == 0);
	cin >> n;
	for( int i = 1; i <= n; i++ ){
		int N;
		cin >> N;
		cout << t.get110100(N) << endl;
	}

	return 0;
}
