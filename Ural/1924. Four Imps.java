import java.io.PrintWriter;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt(); 
		if( n%2==0 ){
			if(n/2%2 == 1){
				out.println("grimy");
			}else{
				out.println("black");
			}
		}else{
			if(n/2%2 == 0){
				out.println("grimy");
			}else{
				out.println("black");
			}
		}
				
		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
