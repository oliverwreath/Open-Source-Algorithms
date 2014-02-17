//dp 

#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>
#include <unordered_set>

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max = INT_MIN;
        int sum = 0;

        F(i, 0, n-1){
            sum += A[i];
            max = max>sum?max:sum;
            sum = sum>0?sum:0;
        }

        return max;
    }
};
