
import java.io.PrintWriter;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int len = 100000; 
		int [] a = new int [len];
		a[0] = 0;
		a[1] = 1; 
		int [] s = new int [len];
		s[0] = 0;
		s[1] = 1;
		int maximum = 0; 
		for(int i = 1; i <= 49999; i++){
			a[2*i] = a[i];
			maximum = Math.max(maximum, a[2*i]); 
			s[2*i] = maximum; 
			a[2*i+1] = a[i] + a[i+1];
			maximum = Math.max(maximum, a[2*i+1]); 
			s[2*i+1] = maximum; 
		}

		while(in.hasNextInt()){
			int n = in.nextInt();
			if(n == 0){
				in.close();
				out.close();
				return;
			}
			out.println(s[n]);
		}

		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};

