



public class Solution {
	public int lengthOfLastWord(String s) {
		int retLen = 0;
		int len = s.length();

		int idx = len -1;
		while( idx >= 0 ){
			if( s.charAt(idx) == ' ' ){
				idx--;
			}else{
				while( idx >= 0 && s.charAt(idx) != ' ' ){
					retLen++;
					idx--;
				}
				break ;
			}
		}

		return retLen; 
	}
}



