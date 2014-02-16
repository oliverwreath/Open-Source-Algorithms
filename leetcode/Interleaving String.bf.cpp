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
	bool helper( string& s1, string& s2, string& s3, int& l, int& m, int& n, int i, int j, int k ){
		if( k < n ){
			if( i < l && s1[i] == s3[k] ){
				if( helper( s1, s2, s3, l, m, n, i+1, j, k+1 ) ){
					return true;
				}
			}
			
			if( j < m && s2[j] == s3[k] ){
				if( helper( s1, s2, s3, l, m, n, i, j+1, k+1 ) ){
					return true;
				}
			}

			return false;
		}

		return true; 
	}

	bool isInterleave(string s1, string s2, string s3) {
		int l = s1.size();
		int m = s2.size();
		int n = s3.size();

		if( l + m != n ){
			return false;
		}

		if( n < 1 ){
			return true;
		}

		return helper( s1, s2, s3, l, m, n, 0, 0, 0 ); 
	}
};
