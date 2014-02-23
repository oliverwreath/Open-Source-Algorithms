package com.ACM;

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
				m = sc.nextInt();
				n = sc.nextInt();
				System.out.println(apple( m, n ));
			}
		}
		sc.close();
		
		return ;
	}
	
	public static int apple( int m, int n ) {
		if( m < 0 ){
			return 0;
		}
		if( m == 0 || n == 1 ){
			return 1; 
		}

		return apple(m-n, n) + apple(m, n-1);
	}
}
