
public class Solution {
	public static int atoi(String str) {
		int len = str.length();
		if( len < 1 ){
			return 0;
		}

		int i = 0;
		while( i < len && str.charAt(i) == ' ' ){
			i++;
		}

		int isPositive = 1;
		if( i < len ){
			if( str.charAt(i) == '+' ){
				i++;
			}else if( str.charAt(i) == '-' ){
				isPositive = -1;
				i++;
			}
		}

		long ret = 0;
		while( i < len ){
			if( str.charAt(i) >= '0' && str.charAt(i) <= '9' ){
				ret *= 10;
				ret += (str.charAt(i) - '0');
				if( ret > Integer.MAX_VALUE ){
					if( isPositive == 1 ){
						return Integer.MAX_VALUE;
					}else{
						return Integer.MIN_VALUE;
					}
				}
				i++;
			}else{
				break;
			}
		}

		return (int)(isPositive * ret);
	}
}
