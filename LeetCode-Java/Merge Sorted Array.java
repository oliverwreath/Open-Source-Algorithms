public class Solution {
	public static void merge(int A[], int m, int B[], int n) {
		int i = m + n-1;
		m--;
		n--;
		while( i >= 0 ){
			if( m < 0 ){
				while( n >= 0 ){
					A[i--] = B[n--];
				}
			}else{
				if( n < 0 ){
					while( m >= 0 ){
						A[i--] = A[m--];
					}
				}else{
					if( A[m] > B[n] ){
						A[i--] = A[m--];
					}else{
						A[i--] = B[n--];
					}
				}
			}
		}

		return ;
	}
}
