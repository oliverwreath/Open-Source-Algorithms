public class Solution {
	public static String addBinary(String a, String b) {
		if( a.length() < b.length() ){
			String tmp = a;
			a = b;
			b = tmp;
		}
		char [] res = new char [a.length()+1];
		String ret;
		int m = a.length()-1;
		int n = b.length()-1; 
		int carry = 0;

		while( m >= 0 ){
			if( n < 0 ){
				int sum = a.charAt(m)-'0' + carry;
				res[m+1] = (char)(sum%2 + 48);
				carry = sum/2;
			}else{
				int sum = a.charAt(m)-'0' + b.charAt(n)-'0' + carry;
				res[m+1] = (char)(sum%2 + 48);
				carry = sum/2;
			}
			m--;
			n--;
		}
		
		res[0] = (char)(carry + 48);
		ret = new String(res);
		if( res[0] == '0' ){
			ret = ret.substring(1, a.length()+1);
		}
			
		return ret; 
	}
}
