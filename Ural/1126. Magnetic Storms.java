import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.LinkedList;
import java.util.Map;

public class Ural{
	class Reading{
		public Reading(int id, int val){
			this.id = id;
			this.val = val;
		}
		int id;
		int val;
	};

	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int m = in.nextInt();
		int cnt = 0;
		LinkedList<Reading> dq = new LinkedList<Reading>();
		Ural ural = new Ural();
		do{
			int n = in.nextInt();
			if( n == -1 ) break;			

			while( !dq.isEmpty() && dq.getLast().val <= n ){
				dq.removeLast();
			}
			cnt++;
			dq.addLast(ural.new Reading(cnt, n));

			if( cnt >= m ){
				while( !dq.isEmpty() && dq.getFirst().id <= (cnt-m) ){
					dq.removeFirst();
				}
				
				if( !dq.isEmpty() ){
					out.println(dq.getFirst().val);
				}
			}
		}while( in.hasNextInt() );

		in.close();
		out.flush();
		return ;
	}
}



