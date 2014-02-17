#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int n = triangle.size();
        if( n == 0 ){
            return 0;
        }

        if( n == 1 ){
            return triangle[0][0];
        }

        vector<int> tmp = triangle[n-1];
        FB(i, n-2, 0){
            F(j, 0, i){
                tmp[j] = MIN2( tmp[j], tmp[j+1] );
            }

            F(j, 0, i){
                tmp[j] += triangle[i][j];
            }
        }

        return tmp[0];
    }
};
