#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int begin = 0;
        int end = n-1;
        int mid = (begin + end)/2;

        while( begin <= end ){
            if( target == A[mid] ){
                return mid;
            }
            if( target < A[mid] ){
                end = mid-1;
            }else{
                begin = mid+1;
            }
            mid = (begin + end)/2;
        }

        while( (mid + 1 <= n) && target > A[mid] ){
            mid++;
        }
        while( (mid - 1 >= 0) && target < A[mid-1] ){
            mid--;
        }

        return mid;
    }
};
