import java.io.*;
import java.util.*;

public class Sum{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int [][] dp = {
			{2, 3, 4, 4, 4, 4, 3, 2},
			{3, 4, 6, 6, 6, 6, 4, 3},
			{4, 6, 8, 8, 8, 8, 6, 4},
			{4, 6, 8, 8, 8, 8, 6, 4},
			{4, 6, 8, 8, 8, 8, 6, 4},
			{4, 6, 8, 8, 8, 8, 6, 4},
			{3, 4, 6, 6, 6, 6, 4, 3},
			{2, 3, 4, 4, 4, 4, 3, 2}
		};

		int n = in.nextInt();
		String str;
		for( int i = 1; i <= n; i++ ){
			str = in.next();
			int a = str.charAt(0) - 'a';
			int b = str.charAt(1) - '1';		
			out.println(dp[a][b]);
		}

		in.close();
		out.flush();
		return;
	}
}
