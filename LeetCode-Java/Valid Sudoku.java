



public class Solution {
	public boolean isValidSudoku(char[][] board) {

		for( int i = 0; i < 9; i++ ){
			boolean [] ht = new boolean [10];
			for( int j = 0; j < 9; j++ ){
				if( board[i][j] != '.' ){
					int tmp = board[i][j] - '0';
					if( ht[tmp] ){
						return false;
					}else{
						ht[tmp] = true;
					}
				}
			}
		}

		for( int j = 0; j < 9; j++ ){
			boolean [] ht = new boolean [10];
			for( int i = 0; i < 9; i++ ){
				if( board[i][j] != '.' ){
					int tmp = board[i][j] - '0';
					if( ht[tmp] ){
						return false;
					}else{
						ht[tmp] = true;
					}
				}
			}
		}

		for( int m = 0; m < 3; m++ ){
			for( int n = 0; n < 3; n++ ){
				boolean [] ht = new boolean [10];
				for( int i = 3*m; i < 3*m+3; i++ ){		
					for( int j = 3*n; j < 3*n+3; j++ ){
						if( board[i][j] != '.' ){
							int tmp = board[i][j] - '0';
							if( ht[tmp] ){
								return false;
							}else{
								ht[tmp] = true;
							}
						}
					}
				}
			}
		}

		return true;

	}
}



