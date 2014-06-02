import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Ural{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int n = in.nextInt();
		ArrayList<ArrayList<Integer>> data = new ArrayList<ArrayList<Integer>>();
		for( int i = 0; i < n; i++ ){
			ArrayList<Integer> line = new ArrayList<Integer>();
			for( int j = 0; j < n; j++ ){
				line.add(0);
			}
			data.add(line);
		}
//		out.print(data.size());out.flush();
		
		int cnt = 1, num_of_steps = 0;
		for( int mark = n-1; mark >= 0; mark-- ){
			int i = 0, j = mark;
			int steps_to_go = num_of_steps++;
			data.get(i).set(j, cnt++);
			while( steps_to_go-- > 0 ){
				i++;
				j++;
				data.get(i).set(j, cnt++);
			}
		}
		num_of_steps -= 2;
		for( int mark = 1; mark < n; mark++ ){
			int i = mark, j = 0;
			int steps_to_go = num_of_steps--;
			data.get(i).set(j, cnt++);
			while( steps_to_go-- > 0 ){
				i++;
				j++;
				data.get(i).set(j, cnt++);
			}
		}

		for( int i = 0; i < n; i++ ){
			for( int j = 0; j < n; j++ ){
				out.print(data.get(i).get(j)+" ");
			}
			out.println();
		}

		in.close();
		out.flush();
		return;
	}
}
