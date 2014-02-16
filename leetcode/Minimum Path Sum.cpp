#define MIN2(a, b) a<b?a:b
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        for( int i = 1; i <= m-1; i++ ){
            grid[i][0] += grid[i-1][0];
        }
        for( int j = 1; j <= n-1; j++ ){
            grid[0][j] += grid[0][j-1];
        }
        for( int i = 1; i <= m-1; i++ ){
            for( int j = 1; j <= n-1; j++ ){
                grid[i][j] += MIN2( grid[i-1][j], grid[i][j-1] );
            }
        }
        return grid[m-1][n-1];
    }
};
