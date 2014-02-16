#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>
#include <unordered_set>

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();

        int end = n/2-1;
        F( i, 0, end ){
            F( j, 0, n-i*2-2 ){
                int tmp = matrix[0+i][j+i];
                matrix[0+i][j+i] = matrix[n-1-j-i][0+i];
                matrix[n-1-j-i][0+i] = matrix[n-1-i][n-1-j-i];
                matrix[n-1-i][n-1-j-i] = matrix[j+i][n-1-i];
                matrix[j+i][n-1-i] = tmp;
            }
        }

        return ;
    }
};
