import java.io.PrintWriter;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt();
		if( n < 5 ){
			out.println("few");
		}else if( n < 10 ){
			out.println("several");
		}else if( n < 20 ){
			out.println("pack");
		}else if( n < 50 ){
			out.println("lots");
		}else if( n < 100 ){
			out.println("horde");
		}else if( n < 250 ){
			out.println("throng");
		}else if( n < 500 ){
			out.println("swarm");
		}else if( n < 1000 ){
			out.println("zounds");
		}else{
			out.println("legion");
		}

		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
