public class Solution {
	public static boolean isAlphaNumeric( char c ){
		return ( Character.isDigit(c) || Character.isLetter(c) );
	}

	public static boolean isPalindrome(String str) {
		int len = str.length();
		if( len < 1 ){
			return true; 
		}

		int i = 0; 
		int j = len-1;
		while( i < j ){
			if( !isAlphaNumeric( str.charAt(i) ) ){
				i++;
				continue; 
			}
			if( !isAlphaNumeric( str.charAt(j) ) ){
				j--;
				continue; 
			}
			if( Character.toLowerCase( str.charAt(i) ) != Character.toLowerCase( str.charAt(j) ) ){
				return false;
			}
			i++;
			j--;
		}

		return true; 
	}
}



