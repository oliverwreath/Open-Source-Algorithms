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
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		if( m < 1 || n < 1 ){
			return 0;
		}

		if( obstacleGrid[0][0] == 1 ){
			return 0;
		}

		vector<int> tmp = vector<int>(n, 1);
		vector<vector<int>> ret = vector<vector<int>>(m, tmp);
		F( i, 1, m-1 ){
			if( obstacleGrid[i][0] == 1 ){
				ret[i][0] = 0;
			}else{
				ret[i][0] = ret[i-1][0];
			}
		}

		F( j, 1, n-1 ){
			if( obstacleGrid[0][j] == 1 ){
				ret[0][j] = 0;
			}else{
				ret[0][j] = ret[0][j-1];
			}
		}

		F( i, 1, m-1 ){
			F( j, 1, n-1 ){
				if( obstacleGrid[i][j] == 1 ){
					ret[i][j] = 0;
				}else{
					ret[i][j] = ret[i-1][j] + ret[i][j-1];
				}
			}
		}

		return ret[m-1][n-1];
	}
};
