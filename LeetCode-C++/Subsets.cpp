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
#include <algorithms>

class Solution {
public:
    void recGeneration( vector<vector<int>>& ret, vector<int> &S, int& len, vector<int>& tmp, int index ){
        F(i, index, len-1){
            tmp.push_back(S[i]);
            ret.push_back(tmp);
            recGeneration( ret, S, len, tmp, i+1 );
            tmp.pop_back();
        }

        return ;
    }

    vector<vector<int> > subsets(vector<int> &S) {
        int len = S.size();
        if( len < 1 ){
            vector<vector<int>> ret;
            vector<int> tmp; 
            ret.push_back(tmp);
            return ret;
        }
        sort(S.begin(), S.end());

        vector<int> tmp; 
        vector<vector<int>> ret;
        ret.push_back(tmp);
        
        //one case handle
        recGeneration( ret, S, len, tmp, 0 );

        return ret;
    }
};
