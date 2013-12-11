#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>
#include <unordered_set>

class Solution {
public:
    int m;
    int n;
    
    bool DFS( vector<vector<char> >& board, int i, int j, string& s, vector<vector<bool> > visited ){
        int len = s.size();
        if( len == 1 ){
            return ( board[i][j] == s[0] );
        }
        if( board[i][j] != s[0] ){
            return false;
        }else{
            visited[i][j] = true;
        }

        bool ret;
        if( i-1 >= 0 && !visited[i-1][j] ){
            string tmp = s.substr(1,len-1);
            ret = DFS( board, i-1, j, tmp, visited );
            if( ret ){ return true; }
        }

        if( j-1 >= 0 && !visited[i][j-1] ){
            string tmp = s.substr(1,len-1);
            ret = DFS( board, i, j-1, tmp, visited );
            if( ret ){ return true; }
        }

        if( i+1 <= m-1 && !visited[i+1][j] ){
            string tmp = s.substr(1,len-1);
            ret = DFS( board, i+1, j, tmp, visited );
            if( ret ){ return true; }
        }

        if( j+1 <= n-1 && !visited[i][j+1] ){
            string tmp = s.substr(1,len-1);
            ret = DFS( board, i, j+1, tmp, visited );
            if( ret ){ return true; }
        }

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

        vector<bool> tmp = vector<bool>(n, false);
        vector<vector<bool> > visited = vector<vector<bool>>(m, tmp);

        F(i, 0, m-1){
            F(j, 0, n-1){
                if( board[i][j] == s[0] ){
                    //DFS begins
                    bool ret = DFS( board, i, j, s, visited );
                    if( ret ){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
