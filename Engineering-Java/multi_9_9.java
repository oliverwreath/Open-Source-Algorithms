package com.java.hello;

public class Solutions {
	public void multi_9_9(){
		for( int i = 1; i < 10; i++ ){
			for( int j = i; j < 10 ; j++ ){
				System.out.print( i + "*" + j + "=" + i * j + " " );
			}
			System.out.println( "");
		}
		
		return ;
	}
}
