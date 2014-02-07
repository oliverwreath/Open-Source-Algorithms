#define F(i, a, b) for(int i = a; i <= b; i++)
#define FF(i, a, b) for( i = a; i <= b; i++)
#define F3(i, a, b) for(int i = a; i <= b; i+=3)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MAX3( a, b, c ) a>b?(a>c?a:c):(b>c?b:c)
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <iterator>
#include <stack>
#include <algorithms>

class Solution {
public:
	int len = 19999;
	vector<int> dp;
	int index = 2;

	int numTrees(int n) {
		dp = vector<int>(len, 0);
		if( n < 0 ){
			return -1;
		}
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		if( n > index ){
			for( int i = index+1; i <= n; i++ ){
				for( int j = 0; j <= i-1; j++ ){
					dp[i] += dp[j]*dp[i-1-j];
				}
			}
		}

		return dp[n];
	}
};
