class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int ret = -1;
       	int len = n;
        for( int i = 0; i < len; i++ ){
        	if( A[i] != elem ){
        		ret++;
        		if( ret < i ){
        			A[ret] = A[i];
        		}
        	}
        }

        return ret + 1;
    }
};
