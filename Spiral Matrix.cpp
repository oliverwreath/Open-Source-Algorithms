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
	enum direction {right, down, left, up};

	int mark = INT_MIN;

	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		int m = matrix.size();
		if( m < 1 ){
			return vector<int>();
		}
		int n = matrix[0].size();
		if( n < 1 ){
			return vector<int>();
		}

		int i = 0;
		int j = 0;
		vector<int> ret;
		ret.push_back(matrix[i][j]);
		matrix[i][j] = mark;
		int counter = 1;
		direction dir = right;
		while( counter < m*n ){
			if( dir == right ){
				while( j+1 < n && matrix[i][j+1] > mark ){
					j++;
					ret.push_back(matrix[i][j]);
					matrix[i][j] = mark;
					counter++;
				}
				dir = down;
			}else if( dir == down ){
				while( i+1 < m && matrix[i+1][j] > mark ){
					i++;
					ret.push_back(matrix[i][j]);
					matrix[i][j] = mark;
					counter++;
				}
				dir = left;
			}else if( dir == left ){
				while( j-1 >= 0 && matrix[i][j-1] > mark ){
					j--;
					ret.push_back(matrix[i][j]);
					matrix[i][j] = mark;
					counter++;
				}
				dir = up;
			}else{
				while( i-1 >= 0 && matrix[i-1][j] > mark ){
					i--;
					ret.push_back(matrix[i][j]);
					matrix[i][j] = mark;
					counter++;
				}
				dir = right;
			}
		}

		return ret; 
	}
};
