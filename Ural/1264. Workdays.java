import java.io.*;
import java.util.*;

public class Sum{
	public static void main( String []  args){
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int a = in.nextInt();
		int b = in.nextInt();
		out.println(a * (b + 1));

		in.close();
		out.flush();
		return;
	}
}
