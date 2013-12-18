#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int n) {
        if( n == 0 ){
            return (vector<int>(1,1));
        }

        if( n == 1 ){
            return (vector<int>(2,1));
        }

        vector<int> ret = vector<int>(n+1,1);
        F( i, 2, n ){
            FB( j, i-1, 1 ){
                ret[j] = ret[j] + ret[j-1];
            }
        }

        return ret;
    }
};
