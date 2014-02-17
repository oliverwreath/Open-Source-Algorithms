#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        if( n < 2 ){
            return n;
        }

        int minima;
        vector<int> ret = vector<int>(n, 1);
        F( i, 1, n-1 ){
            if( ratings[i] > ratings[i-1] ){
                ret[i] = MAX2( ret[i], ret[i-1]+1 );
            }
        }

        int sum = ret[n-1];
        FB( i, n-2, 0 ){
            if( ratings[i] > ratings[i+1] ){
                ret[i] = MAX2( ret[i], ret[i+1]+1 );
            }

            sum += ret[i];
        }

        return sum ; 
    }
};
