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
	int longestConsecutive(vector<int> &num) {
		int len = num.size();
		if( len == 0 ){
			return 0;
		}

		sort( num.begin(), num.end() );

		int maxlen = 1;
		int tmplen = 1;
		F( i, 1, len-1 ){
			if( num[i] == num[i-1]+1 ){
				tmplen++;
				maxlen = tmplen>maxlen?tmplen:maxlen;
			}else if( num[i] == num[i-1] ){

			}else{
				tmplen = 1;
			}
		}

		return maxlen;
	}
};
