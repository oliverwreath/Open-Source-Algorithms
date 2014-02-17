#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calc( vector<vector<int> > & triangle, int tmpSum, int i, int j, int& n ){
        if( i < n-1 ){
            tmpSum += triangle[i][j];
            int ret1 = calc( triangle, tmpSum, i+1, j, n );
            int ret2 = calc( triangle, tmpSum, i+1, j+1, n ); 
            return MIN2(ret1, ret2);
        }else{
            //last row
            tmpSum += triangle[i][j];
            return tmpSum;
        }
    }

    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if( n == 0 ){
            return 0;
        }

        if( n == 1 ){
            return triangle[0][0];
        }

        int tmpSum = 0;
        int min;
        int i = 0;
        int j = 0;
        min = calc( triangle, tmpSum, i, j, n );

        return min;
    }
};
