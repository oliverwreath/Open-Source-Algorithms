import java.io.*;
import java.util.*;

public class Sum{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		Vector<Vector<Integer>> data = new Vector<Vector<Integer>>();

		int n = in.nextInt();
		for( int i = 0; i < n; i++ ){
			Vector<Integer> lineData = new Vector<Integer>();
			for( int j = 0; j < n; j++ ){
				lineData.add(in.nextInt());
			}
			data.add(lineData);
		}

		for( int mark = 0; mark < n; mark++ ){
			for( int i = mark, j = 0; i >= 0; i--, j++ ){
				out.println(data.elementAt(i).elementAt(j));
			}
		}

		for( int mark = 1; mark < n; mark++ ){
			for( int i = n-1, j = mark; j < n; i--, j++ ){
				out.println(data.elementAt(i).elementAt(j));
			}
		}

		in.close();
		out.flush();
		return;
	}
}
