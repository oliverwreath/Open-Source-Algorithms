public class Solution {
	public boolean isNumber(String str) {
		int len = str.length();

		int i = 0;
		while( i < len ){
			if( str.charAt(i) == ' ' ){
				i++;
			}else{
				break;
			}
		}

		if( i < len && (str.charAt(i) == '+' || str.charAt(i) == '-') ){
			i++;
		}

		boolean eYet = false; 
		boolean numYet = false; 
		boolean dotYet = false; 
		boolean breakYet = false;
		while( i < len ){ 
			if( str.charAt(i) >= '0' && str.charAt(i) <= '9' ){ 
				if( breakYet ){
					return false;
				}
				numYet = true; 
			}else if( str.charAt(i) == 'e' ){
				if( !numYet || eYet || breakYet ){
					return false;
				} 
				eYet = true; 
				numYet = false; 
				if( i+1 < len && (str.charAt(i+1) == '+' || str.charAt(i+1) == '-') ){
					i++;
				}
			}else if( str.charAt(i) == '.' ){
				if( eYet || dotYet || breakYet ){
					return false;
				} 
				dotYet = true; 
			}else{
				break;
			}
			i++;
		} 

		while( i < len ){ 
			if( str.charAt(i) == ' ' ){
				i++;
			}else{
				return false;
			}
		}

		return numYet; 
	}
}



