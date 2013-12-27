#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int l = s1.size();
		int m = s2.size();
		int n = s3.size();

		if( l + m != n ){
			return false;
		}

		bool ret [l+1][m+1];
		ret[0][0] = true;

		F( i, 1, l ){
			ret[i][0] = s1[i-1] == s3[i-1] && ret[i-1][0]; 
		}

		F( j, 1, m ){
			ret[0][j] = s2[j-1] == s3[j-1] && ret[0][j-1]; 
		}

		F( i, 1, l ){
			F( j, 1, m ){
				ret[i][j] = ( s1[i-1] == s3[i+j-1] && ret[i-1][j] ) || ( s2[j-1] == s3[i+j-1] && ret[i][j-1] );
			}
		}

		return ret[l][m]; 
	}
};
