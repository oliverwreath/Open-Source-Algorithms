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
	vector<vector<int> > generateMatrix(int n) {
		if( n < 1 ){
			return vector<vector<int>>();
		}
		if( n == 1 ){
			return vector<vector<int>>(1, vector<int>(1,1));
		}
		if( n == 2 ){
			vector<vector<int> > ret = vector<vector<int>>(2, vector<int>(2,1));
			ret[0][1] = 2;
			ret[1][0] = 4;
			ret[1][1] = 3;
			return ret;
		}
		vector<vector<int> > ret = vector<vector<int>>(n, vector<int>(n,0));

		int count = 2;
		int i = 0;
		int j = 0;
		ret[i][j] = 1;
		enum Dir {right, down, left, up};
		Dir dir = right;

		while( count <= n*n ){
			if( dir == right ){
				//to right
				while( 1 ){
					j++;
					if( j > n-1 || ret[i][j] != 0 ){
						//to down
						dir = down;
						j--;
						break;
					}else{
						ret[i][j] = count++;
					}
				}
			}else if( dir == down ){
				//to down
				while( 1 ){
					i++;
					if( i > n-1 || ret[i][j] != 0 ){
						//to left
						dir = left;
						i--;
						break;
					}else{
						ret[i][j] = count++;
					}
				}
			}else if( dir == left ){
				//to left
				while( 1 ){
					j--;
					if( j < 0 || ret[i][j] != 0 ){
						//to up
						dir = up;
						j++;
						break;
					}else{
						ret[i][j] = count++;
					}
				}
			}else if( dir == up ){
				//to up
				while( 1 ){
					i--;
					if( i < 0 || ret[i][j] != 0 ){
						//to right
						dir = right;
						i++;
						break;
					}else{
						ret[i][j] = count++;
					}
				}
			}
		}

		return ret; 
	}
};
