/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define F(i, a, b) for( int i = a; i <= b; i++ )
#define FB(i, a, b) for( int i = a; i >= b; i-- )

#include <vector>

class Solution {
public:
	int uniquePaths(int m, int n) {
		if( m < 1 || n < 1 ){
			return 0;
		}

		if( m == 1 || n == 1 ){
			return 1;
		}

		if( m > n ){
			int tmp = m;
			m = n;
			n = tmp;
		}
		//m >= n;
		vector<int> tmp = vector<int>(n, 1);
		vector<vector<int>> ret = vector<vector<int>>(m, tmp);
		F( i, 1, m-1 ){
			F( j, 1, n-1 ){
				ret[i][j] = ret[i-1][j] + ret[i][j-1];
			}
		}

		return ret[m-1][n-1];
	}
};
