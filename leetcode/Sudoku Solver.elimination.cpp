#define F(i, a, b) for(int i = a; i <= b; i++)
#define F3(i, a, b) for(int i = a; i <= b; i+=3)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
	void update( vector<vector<char> >& board, vector< vector< vector<bool> > >& ret, int& i, int& j, int& k ){
		board[i][j] = (char)(k+49);
		F( l, 0, 8 ){
			ret[i][l][k] = false;
		}
		F( l, 0, 8 ){
			ret[l][j][k] = false;
		}

		int m = i/3*3;
		int n = j/3*3;
		F( l, m, m+2 ){
			F( p, n, n+2 ){
				ret[l][p][k] = false;
			}
		}
	}

	void solveSudoku( vector<vector<char> > &board ) {
		vector< vector< vector<bool> > > ret = vector< vector< vector<bool> > >(9, vector< vector<bool> >(9, vector<bool>(9, true) ) );

		//row
		F( i, 0, 8 ){
			F( j, 0, 8 ){
				if( board[i][j] != '.' ){
					F( k, 0, 8 ){
						ret[i][k][board[i][j]-49] = false;
					}
				}
			}
		}

		//col
		F( j, 0, 8 ){
			F( i, 0, 8 ){
				if( board[i][j] != '.' ){
					F( k, 0, 8 ){
						ret[k][j][board[i][j]-49] = false;
					}
				}
			}
		}

		//blocks
		F3( m, 0, 6 ){
			F3( n, 0, 6){
				F( i, m, m+2 ){
					F( j, n, n+2 ){
						if( board[i][j] != '.' ){
							F( k, m, m+2 ){
								F( l, n, n+2 ){
									ret[k][l][board[i][j]-49] = false;
								}
							}
						}
					}
				}
			}
		}

		bool flag = true;
		while( flag ){
			//until changes happened flag is false;
			flag = false;
			F( i, 0, 8 ){
				F( j, 0, 8 ){
					if( board[i][j] == '.' ){
						int count = 0;
						F( k, 0, 8 ){
							if( ret[i][j][k] ){
								count ++;
							}
						}
						if( count == 1 ){
							flag = true; 
							F( k, 0, 8 ){
								if( ret[i][j][k] ){
									update( board, ret, i, j, k ); 
								}
							}
						}
					}
				}
			}
		}

		return ;
	}
};
