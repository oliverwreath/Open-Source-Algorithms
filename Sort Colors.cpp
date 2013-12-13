#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>
#include <unordered_set>

class Solution {
public:
    void swap( int A[], int& a, int& b ){
        if( a == b ){
            return ;
        }
        int tmp = A[a];
        A[a] = A[b];
        A[b] = tmp;
        return ;
    }

    void sortColors(int A[], int n) {
        if( n == 0 ){
            return ;
        }

        int begin = 0;
        int end = n-1;
        int a = 0;
        int b = 0;
        int c = 0;
        while( begin < end ){
            while( begin < end && A[begin] < 2 ){
                if( A[begin] == 1 ){
                    A[begin] = 0;
                    a--;
                    b++;
                }
                begin++;
            }

            while( begin < end && A[end] > 0 ){
                if( A[end] == 1 ){
                    A[end] = 2;
                    c--;
                    b++;
                }
                end--;
            }

            swap(A, begin, end);
        }

        if( b > 0 ){
            if( A[begin] == 0 ){
                while( a++ < 0 ){
                    A[begin--] = 1;
                }
                while( c++ < 0 ){
                    A[++end] = 1;
                }
            }
            else{
                while( a++ < 0 ){
                    A[--begin] = 1;
                }
                while( c++ < 0 ){
                    A[end++] = 1;
                }
            }
        }

        return ;
    }
};
