import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main{
	public static void main( String [] args ){
		int t;
		int m;
		int n;
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		if( sc.hasNext() ){
			t = sc.nextInt();
			for( int i = 1; i <= t; i++ ){
				n = sc.nextInt();
				System.out.println((int)Math.sqrt(n));
			}
			
		}
		
		sc.close();
		return ;
	}
}
