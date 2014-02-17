public class Solution {
	public int removeDuplicates(int[] A) {
		int len = A.length;
		if( len < 3 ){
			return len;
		}
		int index = 1;
		int processing = A[0];
		boolean isTwice = false;
		for( int i = 1; i < A.length; i++ ){
			if( A[i] == processing ){
				if( isTwice ){
					len--;
				}else{
					isTwice = true;
					if( index < i ){
						A[index] = A[i];
					}
					index++;
				}
			}else{
				processing = A[i];
				isTwice = false;
				if( index < i ){
					A[index] = A[i];
				}
				index++;
			}
		}
		return len;
	}
}
