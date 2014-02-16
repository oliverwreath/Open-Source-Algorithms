class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if( m == 0 || n == 0 ){
            return;
        }
        if( m == 1 ){
            for( int j = 0; j <= n-1; j++ ){
                if( matrix[0][j] == 0 ){
                    for( int j = 0; j <= n-1; j++ ){
                        matrix[0][j] = 0;
                    }
                    break;
                }
            }
            return;
        }
        if( n == 1 ){
            for( int i = 0; i <= m-1; i++ ){
                if( matrix[i][0] == 0 ){
                    for( int i = 0; i <= m-1; i++ ){
                        matrix[i][0] = 0;
                    }
                    break;
                }
            }
            return;
        }
        bool xs = false;
        bool ys = false;
        if( matrix[0][0] == 0 ){
            xs = true;
            ys = true;
        }
        else{
            for( int i = 0; i <= m-1; i++ ){
                if( matrix[i][0] == 0 ){
                    xs = true;
                    break;
                }
            }
            for( int j = 0; j <= n-1; j++ ){
                if( matrix[0][j] == 0 ){
                    ys = true;
                    break;
                }
            }
        }
        for( int i = 1; i <= m-1; i++ ){
            for( int j = 1; j <= n-1; j++ ){
                if( matrix[i][j] == 0 ){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            } 
        }
        for( int i = 1; i <= m-1; i++ ){
            if( matrix[i][0] == 0 ){
                for( int j = 1; j <= n-1; j++ ){
                    matrix[i][j] = 0;
                }
            }
        }
        for( int j = 1; j <= n-1; j++ ){
            if( matrix[0][j] == 0 ){
                for( int i = 1; i <= m-1; i++ ){
                    matrix[i][j] = 0;
                }
            }
        }
        if( xs ){
            for( int i = 0; i <= m-1; i++ ){
                matrix[i][0] = 0;          
            }
        }
        if( ys ){
            for( int j = 0; j <= n-1; j++ ){
                matrix[0][j] = 0;
            }
        }
    }
};
