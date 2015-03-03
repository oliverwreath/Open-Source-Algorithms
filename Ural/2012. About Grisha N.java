import java.io.*;
import java.util.*;

public class Sum
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int f = in.nextInt();
		if( f >= 7 ){
			out.println("YES");
		}else{
			out.println("NO");
		}

		out.flush();
	}
}
