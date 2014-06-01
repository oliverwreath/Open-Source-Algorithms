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

int main(){
	int n, a, b;
	char ch;
	int dp[8][8] = {
		{2, 3, 4, 4, 4, 4, 3, 2},
		{3, 4, 6, 6, 6, 6, 4, 3},
		{4, 6, 8, 8, 8, 8, 6, 4},
		{4, 6, 8, 8, 8, 8, 6, 4},
		{4, 6, 8, 8, 8, 8, 6, 4},
		{4, 6, 8, 8, 8, 8, 6, 4},
		{3, 4, 6, 6, 6, 6, 4, 3},
		{2, 3, 4, 4, 4, 4, 3, 2}
	};
	cin >> n;
	string str;
	for( auto i = 1; i <= n; i++ ){
		cin >> str;
		sscanf(str.c_str(), "%c%d", &ch, &b);
		a = ch - 'a';
		b--;
		cout << dp[a][b] << endl;
	}

	return 0;
}
