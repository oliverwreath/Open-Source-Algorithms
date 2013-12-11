#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>

class Solution {
public:
    //bool 

    bool wordBreak( string &s, unordered_set<string> &dict ) {
        int len = s.size();
        vector<bool> dp = vector<bool>(len+1, false);
        dp[0] = true;

        F(i, 1, len){
            F(j, 0, i-1){
                if( dp[j] == true && ( dict.find( s.substr(j, i-j) ) != dict.end() ) ){
                    dp[i] = true;
                }
            }
        }

        return dp[len];
    }
};
