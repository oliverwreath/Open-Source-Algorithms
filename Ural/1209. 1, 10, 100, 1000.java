import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Ural{
	final BigInteger LENGTH_OF_DP = new BigInteger("2147483647"); 
	Set<BigInteger> dp = new HashSet<BigInteger>();
	private void init(){
		BigInteger i = new BigInteger("1"), step = new BigInteger("1");
		while( i.compareTo(LENGTH_OF_DP) < 0  ){
			dp.add(i);
			i = i.add(step);
			step = step.add(new BigInteger("1"));
		}
		return ;
	}

	public int get110100(int n){
		return (dp.contains(new BigInteger(Integer.toString(n)))?1:0);
	}

	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		Ural t = new Ural();
		t.init();
		int n = in.nextInt();
		for( int i = 0; i < n; i++ ){
			out.println(t.get110100(in.nextInt()));
		}

		in.close();
		out.flush();
		return;
	}
}
