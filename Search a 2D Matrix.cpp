#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target){
        int m = matrix.size();
        if( m == 0 ){
            return false;
        }
        int n = matrix[0].size();
        if( n == 0 ){
            return false;
        }

        int begin = 0;
        int end = m*n-1;
        int mid = (begin + end)/2;
        while( begin <= end ){
            if( target == matrix[mid/n][mid%n] ){
                return true;
            }
            if( target < matrix[mid/n][mid%n] ){
                end = mid-1;
            }
            else{
                begin = mid+1;
            }
            mid = (begin + end)/2;
        }

        return false;
    }
};
