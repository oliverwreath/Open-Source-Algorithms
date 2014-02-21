import java.util.Stack;

public class Solution {
	public static boolean isValid(String s) {
		int len = s.length();
		Stack<Character> st = new Stack<Character>(); 
		for( int i = 0; i <= len-1; i++ ){
			if( s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{' ){
				st.push(s.charAt(i));
			}else{
				if( s.charAt(i) == ')' ){
					if( !st.empty() && st.peek() == '(' ){
						st.pop();
						continue;
					}else{
						return false;
					}
				}else if( s.charAt(i) == ']' ){
					if( !st.empty() && st.peek() == '[' ){
						st.pop();
						continue;
					}else{
						return false;
					}
				}else if( s.charAt(i) == '}' ){
					if( !st.empty() && st.peek() == '{' ){
						st.pop();
						continue;
					}else{
						return false;
					}
				}
			}
		}

		if( st.empty() ){
			return true; 
		}else{
			return false; 
		}
	}
}




