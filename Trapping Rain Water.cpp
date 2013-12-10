class Solution {
public:
    int* left;

    int trap(int A[], int n) {
        if( n < 3 ){
            return 0;
        }
        //max left
        int max = INT_MIN;
        left = new int [n]();
        for( int i = 0; i <= n-2; i++ ){
            if( max < A[i] ){
                max = A[i];
            }
            left[i+1] = max;
        }

        //calc
        int sum = 0;
        max = INT_MIN;
            if( max < A[n-1] ){
                max = A[n-1];
            }
        for( int i = n-2; i >= 1; i-- ){
            int tmp = min( left[i], max ) - A[i];
            if( tmp > 0 ){
                sum += tmp;
            }
            if( max < A[i] ){
                max = A[i];
            }
        }

        delete [] left;
        return sum;
    }
};
