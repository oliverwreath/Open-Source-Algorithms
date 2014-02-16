#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>
#include <unordered_set>

class Solution {
public:
    int m;
    int n;
    
    bool DFS( vector<vector<char> >& board, int i, int j, string& s ){
        int len = s.size();
        char tmpp = board[i][j];
        if( len == 1 ){
            return ( board[i][j] == s[0] );
        }
        if( board[i][j] != s[0] ){
            return false;
        }else{
            board[i][j] = '#';
        }

        bool ret;
        if( i-1 >= 0 ){
            string tmp = s.substr(1,len-1);
            ret = DFS( board, i-1, j, tmp );
            if( ret ){ board[i][j] = tmpp; return true; }
        }

        if( j-1 >= 0 ){
            string tmp = s.substr(1,len-1);
            ret = DFS( board, i, j-1, tmp );
            if( ret ){ board[i][j] = tmpp; return true; }
        }

        if( i+1 <= m-1 ){
            string tmp = s.substr(1,len-1);
            ret = DFS( board, i+1, j, tmp );
            if( ret ){ board[i][j] = tmpp; return true; }
        }

        if( j+1 <= n-1 ){
            string tmp = s.substr(1,len-1);
            ret = DFS( board, i, j+1, tmp );
            if( ret ){ board[i][j] = tmpp; return true; }
        }

        board[i][j] = tmpp;
        return false;
    }

    bool exist(vector<vector<char> >& board, string s){
        m = board.size();
        if( m == 0 ){
            return false;
        }
        n = board[0].size();
        if( n == 0 ){
            return false;
        }
        int len = s.size();
        if( len == 0 ){
            return false;
        }

//        vector<bool> tmp = vector<bool>(n, false);
//        vector<vector<bool> > visited = vector<vector<bool>>(m, tmp);

        F(i, 0, m-1){
            F(j, 0, n-1){
                if( board[i][j] == s[0] ){
                    //DFS begins
                    bool ret = DFS( board, i, j, s );
                    if( ret ){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
