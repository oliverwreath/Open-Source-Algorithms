



public class Solution {
	public int candy(int[] ratings) {
		int len = ratings.length;
		int [] ret = new int [len]; 
		ret[0] = 1; 
		for( int i = 1; i <= len-1; i++ ){ 
			if( ratings[i] > ratings[i-1] ){ 
				ret[i] = ret[i-1] + 1; 
			}else{
				ret[i] = 1;
			}
		} 

		int sum = ret[len-1]; 
		for( int i = len-2; i >= 0; i-- ){ 
			if( ratings[i] > ratings[i+1] ){ 
				ret[i] = Math.max( ret[i+1] +1, ret[i] ); 
			} 
			sum += ret[i]; 
		} 

		return sum; 
	}
}



