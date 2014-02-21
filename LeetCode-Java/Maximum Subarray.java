public class Solution {
	public static int maxSubArray(int[] Ary) {
		int len = Ary.length;

		if( len < 1 ){
			return 0;
		}

		//int [] dp = new int [len];
		int max = Integer.MIN_VALUE;
		int sum = 0;
		for( int i = 0; i < len; i++ ){
			sum += Ary[i];
			max = Math.max(sum, max);
			sum = Math.max(sum, 0);
		}

		return max; 
	}
}
