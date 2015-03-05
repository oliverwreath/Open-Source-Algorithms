import java.io.PrintWriter;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		//filtering out the primes 
		int len = 163842; 
		boolean [] array = new boolean [len];
		int end = (int)Math.sqrt(len);
		for(int i = 2; i <= len-1; i++){
			array[i] = true; 
		}
		for(int i = 2; i <= end; i++){
			if(array[i]){
				int index = i+i; 
				int step = i; 
				while(index < len){
					array[index] = false; 
					index += step;
				}
			}
		}

		//populate primeArray
		int [] primeArray = new int [15001]; 
		int idx = 1; 
		for(int i = 2; i <= len-1; i++){
			if(array[i]){
				primeArray[idx++] = i; 
			}
		}

		//retrieve results 
		int k = in.nextInt();
		for(int i = 1; i <= k; i++){
			int n = in.nextInt(); 
			out.println(primeArray[n]); 
		}

		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
