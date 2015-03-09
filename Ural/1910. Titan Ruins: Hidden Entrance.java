import java.io.PrintWriter;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt();
		int [] vt = new int [n];
		for(int i = 0; i < n; i++){ 
			vt[i] = in.nextInt();
		}

		int sum = vt[0] + vt[1] + vt[2]; 
		int max = sum; 
		int idx = 2; 
		for(int i = 3; i < n; i++){
			sum += vt[i];
			sum -= vt[i-3];
			if(sum > max){
				max = sum; 
				idx = i; 
			}
		}

		out.print(max);
		out.print(" ");
		out.println(idx);
				
		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
