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
	//methods
	void recGeneration( int depth, vector<int>& tmp, vector<vector<int>>& ret, int& n, int& k ){
		//one call per depth
		if( depth == 0 ){
			FF( tmp[0], 1, n-k ){
				recGeneration( 1, tmp, ret, n, k );
			}
		}else if( depth < k-1 ){
			FF( tmp[depth], tmp[depth-1]+1, n-k+depth+1 ){
				recGeneration( depth+1, tmp, ret, n, k );
			}
		}else{
			FF( tmp[depth], tmp[depth-1]+1, n-k+depth+1 ){
				ret.push_back( tmp );
			}
			return ;
		}

		return ;
	}

	vector<vector<int> > combine(int n, int k){
		if( n < 1 || k < 1 ){
			return (vector<vector<int>>());
		}

		if( k == 1 ){
			vector<vector<int>> ret;
			F(i, 1, n){ 
				vector<int> tmp = vector<int>(1, i);
				ret.push_back( tmp );
			}
			return ret; 
		}

		if( k == n ){
			vector<vector<int>> ret;
			vector<int> tmp;
			F( i, 1, n ){
				tmp.push_back(i);
			}
			ret.push_back(tmp);
			return ret; 
		}

		vector<vector<int>> ret;
		vector<int> tmp = vector<int>(k);
		int depth = 0;

		recGeneration( depth, tmp, ret, n, k );
		tmp = vector<int>(k);
		F( i, 0, k-1 ){
			tmp[i] = i+(n-k+1);
		}
		ret.push_back(tmp);

		return ret;
	}
};
