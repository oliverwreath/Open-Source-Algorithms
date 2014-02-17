public class Solution {
	public int removeDuplicates(int[] A) {
		int len = A.length;
		if( len < 1 ){
			return len;
		}
		if( len < 2 ){
			return 1;
		}
		int index = 1;
		int processing = A[0];
		for( int i = 1; i < A.length; i++ ){
			if( A[i] == processing ){
				len--;
			}else{
				processing = A[i];
				if( index < i ){
					A[index] = A[i];
				}
				index++;
			}
		}
		return len;
	}
}
