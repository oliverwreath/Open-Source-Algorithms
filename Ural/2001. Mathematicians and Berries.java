import java.io.PrintWriter;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int a1 = in.nextInt(); 
		int b1 = in.nextInt(); 
		int tmp = in.nextInt(); 
		int b2 = in.nextInt(); 
		int a3 = in.nextInt(); 
		tmp = in.nextInt(); 
		
		out.print(a1 - a3);
		out.print(" ");
		out.println(b1 - b2);
				
		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
