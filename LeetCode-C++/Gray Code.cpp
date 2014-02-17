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
	vector<int> grayCode(int n) {
		if( n < 1 ){
			return vector<int>(1, 0);
		}
		if( n < 2 ){
			vector<int> ret = {0, 1};
			return ret; 
		}
		if( n < 3 ){
			vector<int> ret = {0, 1, 3, 2};// +2
			return ret; 
		}
		if( n < 4 ){
			vector<int> ret = {0, 1, 3, 2, 6, 7, 5, 4};// +4
			return ret; 
		}

		vector<int> ret = {0, 1, 3, 2, 6, 7, 5, 4};// +4
		int base = 8;
		F( i, 4, n ){
			int len = ret.size();
			ret.resize(len*2);
			F( j, 1, len ){
				ret[2*len-j] = ret[j-1]+base;
			}
			base *= 2; 
		}
		return ret;
	}
};
