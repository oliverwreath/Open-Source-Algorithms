#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>
#include <unordered_set>

class Solution {
public:
    void sortColors(int A[], int n) {
        if( n == 0 ){
            return ;
        }

        int a = 0;
        int b = 0;
        int c = 0;
        F( i, 0, n-1 ){
            if(A[i] == 0){
                a++;
            }else if(A[i] == 1){
                b++;
            }else{
                c++;
            }
        }

        F( i, 0, n-1 ){
            if( a-- > 0 ){
                A[i] = 0;
            }else if( b-- > 0 ){
                A[i] = 1;
            }else{
                A[i] = 2;
            }
        }

        return ;
    }
};
