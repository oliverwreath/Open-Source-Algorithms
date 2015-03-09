import java.io.PrintWriter;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int m = in.nextInt();
		int n = in.nextInt();
		int ret = (m-1) + (n-1) + (m-1) * (n-1);

		if(ret%2 == 1){
			out.println("[:=[first]");
		}else{
			out.println("[second]=:]");
		}
				
		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
