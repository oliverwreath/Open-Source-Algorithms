#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>

class Solution {
public:
    int search(int A[], int n, int target) {
        int begin = 0;
        int end = n-1;
        int mid = (begin + end)/2;

        while( begin <= end ){
            if( target == A[mid] ){
                return mid;
            }
            if( A[begin] <= A[mid] ){
                if( target < A[mid] && target >= A[begin] ){
                    end = mid - 1;
                }else{
                    begin = mid + 1;
                }
            }
            else{
                if( target > A[mid] && target <= A[end] ){
                    begin = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
            mid = (begin + end)/2;
        }
        return -1;
    }
};
