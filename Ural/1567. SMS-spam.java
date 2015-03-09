

import java.io.PrintWriter;
import java.util.Hashtable;
import java.util.Scanner;

public class ACM
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		String str = in.nextLine();
		Hashtable<Character, Integer> ht = new Hashtable<Character, Integer>(); 
		ht.put('a', 1);
		ht.put('b', 2);
		ht.put('c', 3);
		ht.put('d', 1);
		ht.put('e', 2);
		ht.put('f', 3);
		ht.put('g', 1);
		ht.put('h', 2);
		ht.put('i', 3);
		ht.put('j', 1);
		ht.put('k', 2);
		ht.put('l', 3);
		ht.put('m', 1);
		ht.put('n', 2);
		ht.put('o', 3);
		ht.put('p', 1);
		ht.put('q', 2);
		ht.put('r', 3);
		ht.put('s', 1);
		ht.put('t', 2);
		ht.put('u', 3);
		ht.put('v', 1);
		ht.put('w', 2);
		ht.put('x', 3);
		ht.put('y', 1);
		ht.put('z', 2);
		ht.put('.', 1);
		ht.put(',', 2);
		ht.put('!', 3);
		ht.put(' ', 1);

		int ret = 0;
		for(int i = 0; i < str.length(); i++){
			ret += ht.get(str.charAt(i));
		}

		out.println(ret);
				
		out.flush();
		in.close();
		out.close();
		
		return; 
	}
};
