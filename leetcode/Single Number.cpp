#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        F( i, 1, n-1 ){
            A[i] ^= A[i-1];
        }

        return A[n-1];
    }
};
