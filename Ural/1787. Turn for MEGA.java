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
		int ret = 0; 
		for(int i = 1; i <= k; i++){
			int tmp = in.nextInt();
			ret += tmp; 
			if(ret > n){
				ret -= n; 
			}else{
				ret = 0;
			}
		}
		out.println(ret); 
				
		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
