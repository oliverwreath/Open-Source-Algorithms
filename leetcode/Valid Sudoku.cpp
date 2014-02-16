#include <unordered_set>
#define F(i,a,b) for( int i = a; i <= b; i++ )

class Solution {
public:
    unordered_set<char> c1;

    bool isValidSudoku(vector<vector<char> > &board) {
        //row
        F(i, 0, 8){
            F(j, 0, 8){
                if( c1.find(board[i][j]) != c1.end() ){
                    return false;
                }
                if( board[i][j] != '.' ){ 
                    c1.insert(board[i][j]); 
                }
            }
            c1.clear();
        }

        //col
        F(j, 0, 8){
            F(i, 0, 8){
                if( c1.find(board[i][j]) != c1.end() ){
                    return false;
                }
                if( board[i][j] != '.' ){ 
                    c1.insert(board[i][j]); 
                }
            }
            c1.clear();
        }

        //block
        F(j, 0, 2){
            F(i, 0, 2){
                if( c1.find(board[i][j]) != c1.end() ){
                    return false;
                }
                if( board[i][j] != '.' ){ 
                    c1.insert(board[i][j]); 
                }
            }
        }
        c1.clear();
        F(j, 0, 2){
            F(i, 3, 5){
                if( c1.find(board[i][j]) != c1.end() ){
                    return false;
                }
                if( board[i][j] != '.' ){ 
                    c1.insert(board[i][j]); 
                }
            }
        }
        c1.clear();
        F(j, 0, 2){
            F(i, 6, 8){
                if( c1.find(board[i][j]) != c1.end() ){
                    return false;
                }
                if( board[i][j] != '.' ){ 
                    c1.insert(board[i][j]); 
                }
            }
        }
        c1.clear();

        F(j, 3, 5){
            F(i, 0, 2){
                if( c1.find(board[i][j]) != c1.end() ){
                    return false;
                }
                if( board[i][j] != '.' ){ 
                    c1.insert(board[i][j]); 
                }
            }
        }
        c1.clear();
        F(j, 3, 5){
            F(i, 3, 5){
                if( c1.find(board[i][j]) != c1.end() ){
                    return false;
                }
                if( board[i][j] != '.' ){ 
                    c1.insert(board[i][j]); 
                }
            }
        }
        c1.clear();
        F(j, 3, 5){
            F(i, 6, 8){
                if( c1.find(board[i][j]) != c1.end() ){
                    return false;
                }
                if( board[i][j] != '.' ){ 
                    c1.insert(board[i][j]); 
                }
            }
        }
        c1.clear();

        F(j, 6, 8){
            F(i, 0, 2){
                if( c1.find(board[i][j]) != c1.end() ){
                    return false;
                }
                if( board[i][j] != '.' ){ 
                    c1.insert(board[i][j]); 
                }
            }
        }
        c1.clear();
        F(j, 6, 8){
            F(i, 3, 5){
                if( c1.find(board[i][j]) != c1.end() ){
                    return false;
                }
                if( board[i][j] != '.' ){ 
                    c1.insert(board[i][j]); 
                }
            }
        }
        c1.clear();
        F(j, 6, 8){
            F(i, 6, 8){
                if( c1.find(board[i][j]) != c1.end() ){
                    return false;
                }
                if( board[i][j] != '.' ){ 
                    c1.insert(board[i][j]); 
                }
            }
        }
        c1.clear();

        return true;
    }
};
