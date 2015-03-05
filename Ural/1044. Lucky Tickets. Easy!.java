import java.io.PrintWriter;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt(); 
		switch(n){
			case 2: out.println(10);
				break; 
			case 4: out.println(670);
				break; 
			case 6: out.println(55252);
				break; 
			case 8: out.println(4816030);
				break; 
		}
		
		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
