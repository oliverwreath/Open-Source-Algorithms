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
#include <tuple>
#include <iterator>
#include <stack>

class Solution {
public:
	int m;
	int n;
	void markingY(vector<vector<char>> &board, int i, int j){
		if( i < 0 || j < 0 || i > m-1 || j > n-1 ){
			return ;
		}
		if( board[i][j] != 'O' ) return ;
		board[i][j] = 'Y';
		markingY( board, i-1, j );
		markingY( board, i+1, j );
		markingY( board, i, j-1 );
		markingY( board, i, j+1 );

		return ;
	}

	void tick( vector<vector<char>> &board ){
		F(i, 0, m-1){
			if( board[i][0] == 'O' ){
				markingY( board, i, 0 );
			}
			if( board[i][n-1] == 'O' ){
				markingY( board, i, n-1 );
			}
		}

		F(j, 0, n-1){
			if( board[0][j] == 'O' ){
				markingY( board, 0, j );
			}
			if( board[m-1][j] == 'O' ){
				markingY( board, m-1, j );
			}
		}

		return ;
	}

	void solve(vector<vector<char>> &board) {
		m = board.size();
		if( m == 0 ){
			return ;
		}
		n = board[0].size();
		if( n == 0 ){
			return ;
		}

		//step 1
		tick(board);

		//step 2
		F( i, 0, m-1 ){
			F( j, 0, n-1 ){
				if( board[i][j] == 'O' ){
					board[i][j] = 'X';
				}
			}
		}

		//step 3
		F( i, 0, m-1 ){
			F( j, 0, n-1 ){
				if( board[i][j] == 'Y' ){
					board[i][j] = 'O';
				}
			}
		}

		return ;
	}
};
