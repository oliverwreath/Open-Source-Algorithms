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
	void combHelper( vector<vector<int> >& ret, vector<int>& cand, int& target, int begin, vector<int>& sol, int& sum ){
		if( begin > 0 && cand[begin] == cand[begin-1] ){
			combHelper( ret, cand, target, begin+1, sol, sum );
			return ;
		}

		if( sum == target ){
			ret.push_back( sol );
			return ;
		}
		if( sum > target ){
			return ;
		}

		for( int i = begin; i < cand.size(); i++ ){
			sum += cand[i];
			sol.push_back(cand[i]);
			combHelper( ret, cand, target, i, sol, sum );
			sum -= cand[i];
			sol.pop_back();
		}

		return ;
	}

	vector<vector<int> > combinationSum(vector<int>& cand, int target){
		int len = cand.size();
		if( len < 1 ){
			return vector<vector<int> >();
		}

		vector<vector<int> > ret;
		sort(cand.begin(), cand.end());
		vector<int> sol;
		int sum = 0;
		combHelper( ret, cand, target, 0, sol, sum );

		return ret; 
	}
};






