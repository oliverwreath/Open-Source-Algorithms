import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();
		map.put('A', 1);
		map.put('P', 1);
		map.put('O', 1);
		map.put('R', 1);
		map.put('B', 2);
		map.put('M', 2);
		map.put('S', 2);
		map.put('D', 3);
		map.put('G', 3);
		map.put('J', 3);
		map.put('K', 3);
		map.put('T', 3);
		map.put('W', 3);

		int currentPos = 1; 
		int ret = 0; 
		int n = in.nextInt();
		for(int i = 1; i <= n; i++){
			String str = in.next();
			int pos = map.get(str.charAt(0));
			ret += Math.abs(currentPos - pos);
			currentPos = pos; 
		}
		out.println(ret);
		out.flush();
		in.close();
		out.close(); 
	}
};
