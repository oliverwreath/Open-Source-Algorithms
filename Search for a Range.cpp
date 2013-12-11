#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int begin = 0;
        int end = n-1;
        int mid = (begin + end)/2;

        while( mid != begin ){
            if( target == A[mid] ){
                break;
            }
            if( target < A[mid] ){
                end = mid;
            }else{
                begin = mid;
            }
            mid = (begin + end)/2;
        }

        while( (mid + 1 <= n-1) && target > A[mid] ){
            mid++;
        }
        while( (mid - 1 >= 0) && target < A[mid] ){
            mid--;
        }


        if( A[mid] != target ){
            return vector<int>(2, -1);
        }
        else{
            vector<int> ret;
            begin = mid;
            end = mid;
            while( (end + 1 <= n-1) && target == A[end+1] ){
                end++;
            }
            while( (begin - 1 >= 0) && target == A[begin-1] ){
                begin--;
            }
            ret.push_back(begin);
            ret.push_back(end);
            return ret;
        }
    }
};
