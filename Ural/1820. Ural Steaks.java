import java.io.PrintWriter;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt(); 
		int k = in.nextInt();
		if(k >= n){
			out.println(2); 
		}else{
			out.println((int)Math.ceil(2.0*n/k)); 
		}

		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
