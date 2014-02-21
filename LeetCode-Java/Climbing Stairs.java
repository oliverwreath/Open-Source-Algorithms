public class Solution {
	public static int climbStairs(int n) {
		int [] dp = new int [n+1];
		dp[0] = 1;

		for( int i = 0; i <= n-2; i++ ){
			dp[i+1] += dp[i];
			dp[i+2] += dp[i];
		}

		dp[n] += dp[n-1];
		return dp[n];
	}
}
