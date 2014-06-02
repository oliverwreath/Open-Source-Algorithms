import java.io.*;
import java.util.*;

public class Ural{
	public void Sum(int n, PrintWriter out){
		if( n == 0 ){
			out.println(1);
		}else if(n < 0){
			out.println(Math.abs(n)* (n-1)/ 2 + 1);
		}else{
			out.println((n+1)* n/ 2);
		}
		out.flush();
		return ;
	}

	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		Ural t = new Ural();
		
		while( in.hasNextInt() ){
			t.Sum(in.nextInt(), out);
		}

		in.close();
		
		return;
	}
}
