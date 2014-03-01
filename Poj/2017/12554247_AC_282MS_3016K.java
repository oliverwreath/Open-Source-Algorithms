import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main{
	public static void main( String [] args ){
		int t;
		int m;
		int n;
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		while( sc.hasNext() ){
			t = sc.nextInt();
			if( t == -1 ){
				sc.close();
				return ;
			}
			int sum = 0;
			int ln = 0;
			for( int i = 1; i <= t; i++ ){
				m = sc.nextInt();
				n = sc.nextInt();
				sum += m * (n - ln);
				ln = n;
			}
			System.out.println(sum+" miles");
		}
		
		sc.close();
		return ;
	}
}