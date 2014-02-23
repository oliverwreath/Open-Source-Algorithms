package com.ACM;

import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main{
	public static void main( String [] args ){
		String str = "             -223 32, 4232  dddddddddddd ";
		ListNode l1 = new ListNode(4);
		ListNode l2 = new ListNode(3);
		int[][] obs = {{0,1}};//0
		int[][] obs2 = {{1,0}};//0
		int[][] obs3 = {
		  {0,0,0},
		  {0,1,0},
		  {0,0,0}
		};//2
		int [] Ary = {2,1,3,4,1,2,1,5,4};
		String a = "111";
		String b = "0";
		int t;
		int m;
		int n;
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		if( sc.hasNext() ){
			t = sc.nextInt();
			for( int i = 1; i <= t; i++ ){
				m = sc.nextInt();
				n = sc.nextInt();
				int ret = apple( m, n );
				System.out.println(ret);
			}
		}
		
		return ;
	}
	
	public static int apple( int m, int n ) {
		if( m < 0 ){
			return 0;
		}
		if( m == 0 || n == 1 ){
			return 1; 
		}

		return apple(m, n-1) + apple(m-n, n);
	}
}
