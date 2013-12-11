#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>

class Solution {
public:
    bool search(int A[], int n, int target) {
        if( n==1 ){
            if( A[0] == target ){
                return true;
            }
            return false;
        }

        int begin = 0;
        int end = n-1;
        int mid = (begin + end)/2;
        int pivot = -1;

        F( i, 0, n-2 ){
            if( A[i] > A[i+1] ){
                pivot = i;
                break;
            }
        }
        if(pivot == -1){
            //not rotated, plain or increasing
            begin = 0;
            end = n-1;
            mid = (begin + end)/2;
            while( begin <= end ){
                if( target == A[mid] ){
                    return true;
                }
                if( target < A[mid] ){
                    end = mid-1;
                }
                else{
                    begin = mid+1;
                }
                mid = (begin + end)/2;
            }
        }
        else{
            begin = 0;
            end = pivot;
            mid = (begin + end)/2;
            while( begin <= end ){
                if( target == A[mid] ){
                    return true;
                }
                if( target < A[mid] ){
                    end = mid-1;
                }
                else{
                    begin = mid+1;
                }
                mid = (begin + end)/2;
            }

            begin = pivot+1;
            end = n-1;
            mid = (begin + end)/2;
            while( begin <= end ){
                if( target == A[mid] ){
                    return true;
                }
                if( target < A[mid] ){
                    end = mid-1;
                }
                else{
                    begin = mid+1;
                }
                mid = (begin + end)/2;
            }
        }

        return false;
    }
};
