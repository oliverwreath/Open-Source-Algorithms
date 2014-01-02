#define F(i, a, b) for(int i = a; i <= b; i++)
#define F3(i, a, b) for(int i = a; i <= b; i+=3)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <unordered_set>
#include <tuple>
#include <iterator>

class Solution {
public:
	bool isValid( vector<vector<char>>& board, int& i, int& j ){
		unordered_set<char> set;
		F(k, 0, 8){
			if( board[i][k] != '.' ){
				if( set.find( board[i][k] ) != set.end() ){
					return false;
				}else{
					set.insert( board[i][k] );
				}
			}
		}

		set.clear();
		F(k, 0, 8){
			if( board[k][j] != '.' ){
				if( set.find( board[k][j] ) != set.end() ){
					return false;
				}else{
					set.insert( board[k][j] );
				}
			}
		}

		set.clear();
		int m = i/3*3;
		int n = j/3*3;
		F( l, m, m+2 ){
			F( p, n, n+2 ){
				if( board[l][p] != '.' ){
					if( set.find( board[l][p] ) != set.end() ){
						return false;
					}else{
						set.insert( board[l][p] );
					}
				}
			}
		}

		return true;
	}

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

	bool backTrackHelper( vector<vector<char>>& board, list< tuple <int, int, list<int> > >& tracking, list< tuple <int, int, list<int> > >::iterator cellPtr ){
		if( cellPtr != (tracking.end()) ){
			int i = get<0>(*cellPtr);
			int j = get<1>(*cellPtr);
			list<int>::iterator candiPtr = get<2>(*cellPtr).begin();
			while( candiPtr != get<2>(*cellPtr).end() ){
				board[i][j] = (char)(*candiPtr+49);
				if( isValid( board, i, j ) ){
					if( backTrackHelper( board, tracking, ++cellPtr ) ){
						return true;
					}
					cellPtr--;
				}
				candiPtr++;
			}
			board[i][j] = '.';
			return false; 
		}

		return true;
	}

	void backTrack( vector<vector<char>>& board, list< tuple <int, int, list<int> > >& tracking, list< tuple <int, int, list<int> > >::iterator ptr ){
		if( ptr != (tracking.end()) ){
			while( !get<2>(*ptr).empty() ){
				board[get<0>(*ptr)][get<1>(*ptr)] = get<2>(*ptr).front()+49;
				if( isValid( board, get<0>(*ptr), get<1>(*ptr) ) ){
					//check rest
					if( backTrackHelper( board, tracking, ptr++ ) ){
						return;
					}
				}
				//next candidate
				board[get<0>(*ptr)][get<1>(*ptr)] = '.';
				get<2>(*ptr).pop_front();
			}
		}

		return ;
	}

	void solveSudoku( vector<vector<char> > &board ) {
		vector< vector< vector<bool> > > ret = vector< vector< vector<bool> > >(9, vector< vector<bool> >(9, vector<bool>(9, true) ) );

		//init for elimination
		int counter = 0;
		//row
		F( i, 0, 8 ){
			F( j, 0, 8 ){
				if( board[i][j] != '.' ){
					counter++;
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
		

		//elimination
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
							counter++;
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

		if( counter < 81 ){
			//init for tracking
			list< tuple <int, int, list<int> > > tracking;

			F( i, 0, 8 ){
				F( j, 0, 8 ){
					if( board[i][j] == '.' ){
						//cell to try
						list<int> tmp;
						F( k, 0, 8 ){
							if( ret[i][j][k] ){
								tmp.push_back(k);
							}
						}
						tracking.push_back( make_tuple( i, j, tmp ) );
					}
				}
			}

			//go tracking
			backTrackHelper( board, tracking, tracking.begin() );
		}

		return ;
	}
};
