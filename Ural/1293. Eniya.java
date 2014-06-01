import java.io.*;
import java.util.*;

public class Sum{
	public static void main( String []  args){
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt();
		int a = in.nextInt();
		int b = in.nextInt();
		out.println(2 * n * a * b);

		in.close();
		out.flush();
		return;
	}
}
