



public class Solution {
	public void setZeroes(int[][] matrix) {
		int m = matrix.length;
		if( m < 1 ){
			return ;
		} 
		int n = matrix[0].length;
		if( n < 1 ){
			return ;
		} 

		if( m == 1 ){ 
			boolean row = false;
			for( int j = 0; j < n; j++ ){
				if( matrix[0][j] == 0 ){
					row = true;
					break;
				}
			}
			if( row ){
				for( int j = 0; j < n; j++ ){
					matrix[0][j] = 0;
				}
				return ;
			}
		} 

		if( n == 1 ){ 
			boolean col = false;
			for( int i = 0; i < m; i++ ){
				if( matrix[i][0] == 0 ){
					col = true;
					break;
				}
			}
			if( col ){
				for( int i = 0; i < m; i++ ){
					matrix[i][0] = 0;
				}
				return ;
			}
		} 

		boolean row = false; 
		boolean col = false; 

		//pre
		if( matrix[0][0] == 0 ){ 
			row = true;
			col = true;
		}else{ 
			for( int j = 1; j < n; j++ ){
				if( matrix[0][j] == 0 ){
					row = true;
					break;
				}
			}
			for( int i = 1; i < m; i++ ){
				if( matrix[i][0] == 0 ){
					col = true;
					break;
				}
			}
		}

		//main
		for( int i = 1; i < m; i++ ){ 
			for( int j = 1; j < n; j++ ){ 
				if( matrix[i][j] == 0 ){
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			} 
		} 

		for( int i = 1; i < m; i++ ){
			if( matrix[i][0] == 0 ){
				for( int j = 1; j < n; j++ ){
					matrix[i][j] = 0;
				}
			}
		}

		for( int j = 1; j < n; j++ ){
			if( matrix[0][j] == 0 ){
				for( int i = 1; i < m; i++ ){
					matrix[i][j] = 0;
				}
			}
		}

		//post
		if( row ){
			for( int j = 0; j < n; j++ ){
				matrix[0][j] = 0;
			}
		}
		if( col ){
			for( int i = 0; i < m; i++ ){
				matrix[i][0] = 0;
			}
		}

		return ;
	} 
} 



