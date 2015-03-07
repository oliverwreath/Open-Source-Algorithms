import java.io.PrintWriter;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n1 = in.nextInt();
		int n2 = in.nextInt();
		if(n1%2 == 0 || (n2%2 == 1)){
			out.println("yes");
		}else{
			out.println("no");
		}

		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
