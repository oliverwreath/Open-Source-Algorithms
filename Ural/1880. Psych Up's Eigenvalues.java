import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Vector;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		// int index1 = 0; 
		int n1 = in.nextInt();
		Vector<Integer> v1 = new Vector<Integer>(n1); 
		for(int i = 0; i < n1; i++){
			v1.add(in.nextInt());  
		}
		int n2 = in.nextInt();
		Vector<Integer> v2 = new Vector<Integer>(n2); 
		for(int i = 0; i < n2; i++){
			v2.add(in.nextInt()); 
		}
		int n3 = in.nextInt();
		Vector<Integer> v3 = new Vector<Integer>(n3); 
		for(int i = 0; i < n3; i++){
			v3.add(in.nextInt()); 
		}

		int j = 0; 
		int k = 0; 
		int ctr = 0; 
		for(int i = 0; i < n1; i++){
			while(j < n2-1 && v2.get(j) < v1.get(i)){
				j++;
			}
			while(k < n3-1 && v3.get(k) < v1.get(i)){
				k++;
			}
			if( v1.get(i).equals(v2.get(j)) && (v2.get(j).equals(v3.get(k))) ){
				ctr++; 
			}
		}
		out.println(ctr);
				
		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
