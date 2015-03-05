import java.io.PrintWriter;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt();
		for( int i = 3; i <= n; i++ ){
			if(n%i == 0){
				out.println(i-1);
				break; 
			}
		}

		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
