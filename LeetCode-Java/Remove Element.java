public class Solution {
	public int removeElement(int[] A, int elem) {
		int len = A.length;
		int ret = -1;
		for( int i = 0; i < len; i++ ){
			if( A[i] != elem ){
				ret ++;
				if( ret < i ){
					A[ret] = A[i];
				}
			}
		}

		return ret +1;
	}
}
