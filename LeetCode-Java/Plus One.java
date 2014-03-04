



public class Solution {
	public int[] plusOne(int[] digits) {
		int len = digits.length;
		int [] ret = new int [len+1];

		int carry = 1;
		for( int i = len ; i >= 1; i-- ){
			ret[i] = digits[i-1] + carry;
			carry = ret[i] / 10; 
			ret[i] %= 10;
		}
		ret[0] = carry;
		if( ret[0] == 0 ){
			ret = Arrays.copyOfRange( ret, 1, len+1 );
		}

		return ret; 
	}
}


