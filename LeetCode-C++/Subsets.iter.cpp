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
    void recGeneration( vector<vector<int>>& ret, vector<int> &S, int& len, int& k, vector<int>& idx, vector<int> tmp, int depth ){
        if( depth < k ){
            FF( idx[depth], idx[depth-1]+1, len-k+depth-1 ){
                tmp.push_back(S[idx[depth]]);
                recGeneration( ret, S, len, k, idx, tmp, depth+1 );
                tmp.pop_back();
            }
        }else{
            FF( idx[depth], idx[depth-1]+1, len-k+depth-1 ){
                tmp.push_back(S[idx[depth]]);
                ret.push_back(tmp);
                tmp.pop_back();
            }
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

        if( len < 2 ){
            vector<vector<int>> ret;
            vector<int> tmp; 
            ret.push_back(tmp);
            ret.push_back(S);
            return ret;
        }
        vector<int> tmp; 
        vector<vector<int>> ret;
        //case 1 empty set
        ret.push_back(tmp);

        //case 2 single ele set
        F(i, 0, len-1){
            tmp.clear();
            tmp.push_back( S[i] );
            ret.push_back(tmp);
        }

        //case 3 other sets
        vector<int> idx = vector<int>(len, -1);

        F( k, 2, len-1 ){
            recGeneration( ret, S, len, k, idx, vector<int>(), 1 );
        }

        //case 4 full ele set
        ret.push_back(S);

        return ret;
    }
};
