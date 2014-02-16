#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>
#include <unordered_set>

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if( n == 0 ){
            return ;
        }

        int index = m+n-1;
        m--;
        n--;
        while( index >= 0 ){
            if( m < 0 ){
                A[index] = B[n--]; 
            }
            else if( n < 0 ){
                A[index] = A[m--];
            }
            else if( A[m] > B[n] ){
                A[index] = A[m--];
            }
            else{
                A[index] = B[n--];            
            }
            index--;
        }

        return ;
    }
};
