



public class Solution {
	public int searchInsert(int[] A, int target) {
		int len = A.length;

		if( target > A[len-1] ){
			return len; 
		}

		for( int i = 0; i <= len-1; i++ ){
			if( target <= A[i] ){
				return i;
			}
		}

		return -1;
	}
}



