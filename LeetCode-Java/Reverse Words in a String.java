public class Solution {
	public String reverseWords(String s) {
		int len = s.length();
		int begin = 0;
		int end = len-1;
		
		//handling proceeding and trailing spaces 
		while( begin <= end && s.charAt(begin) == ' ' ){
			begin++;
		}
		while( begin <= end && s.charAt(end) == ' ' ){
			end--;
		}

		if( begin > end ){
			return new String();
		}
		//counting the spaces 
		int allSpCnt = 0;
		int tmpCnt = 0;
		for( int i = begin+1; i <= end; i++ ){
			if( s.charAt(i) == ' ' ){
				tmpCnt++;
			}else{
				if( tmpCnt > 1 ){
					allSpCnt += tmpCnt - 1;	
				}
				tmpCnt = 0;
			}
		}

		//reversing 
		len = end - begin + 1 - allSpCnt; 

		char [] ret = new char [len]; 
		int tmpEnd = begin; 
		int fillingIdx = len-1; 
		while( tmpEnd < end ){ 
			if( s.charAt(tmpEnd+1) != ' ' ){
				tmpEnd++;
			}else{
				int tmpTmpEnd = tmpEnd;
				while( begin <= tmpTmpEnd ){ 
					ret[fillingIdx--] = s.charAt(tmpTmpEnd--); 
				}
				ret[fillingIdx--] = ' ';
				begin = tmpEnd + 2;
				while( s.charAt(begin) == ' ' ){
					begin++;
				}
				tmpEnd = begin;
			}
		}
		
		int tmpTmpEnd = tmpEnd;
		while( begin <= tmpTmpEnd ){ 
			ret[fillingIdx--] = s.charAt(tmpTmpEnd--); 
		}
		
		return new String(ret);
	}
}
