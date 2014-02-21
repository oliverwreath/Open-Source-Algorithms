public class Solution {
	public int maxProfit(int[] pri) {
		int len = pri.length; 
		if( len < 1 ){
			return 0;
		}
		int min = pri[0];
		int max = 0; 
		for( int i = 1; i < len; i++ ){
			max = Math.max(max, pri[i] - min);
			min = Math.min(pri[i], min);
		}

		return max;
	}
}
