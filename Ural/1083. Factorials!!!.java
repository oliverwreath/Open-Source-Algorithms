import java.io.PrintWriter;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt();
		String str = in.next();
		int k = str.length();
		
		int begin = n; 
		int end = n % k; 
		if(end == 0) end = k; 
		int ret = 1; 
		for(int i = begin; i >= end; i=i-k){ 
			ret *= i; 
		}

		out.println(ret); 
		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
