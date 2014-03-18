package com.java.hello;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Date;

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
	
	public int factorial( int n ){
		if( n == 1 ){
			return 1; 
		} 
		return n * factorial(n - 1);
	}
	
	public int factorialItr( int n  ){
		int ret = 1;
		for( int i = 2; i <= n; i++ ){
			ret *= i;
		}
		
		return ret;
	}
	
	public void visualCalendar(){
		String temp = "2005-02-01";
		DateFormat ft = new SimpleDateFormat( "yyyy-MM-dd" );
		try {
			Date date = ft.parse(temp);
			
			Calendar cal = new GregorianCalendar();		
			cal.setTime(date);
			//System.out.println(cal.get(Calendar.DAY_OF_WEEK));
			//System.out.println(cal.getActualMaximum(Calendar.DATE));
			int pre = cal.get(Calendar.DAY_OF_WEEK);
			int max = cal.getActualMaximum(Calendar.DATE);
			
			System.out.println( "日\t一\t二\t三\t四\t五\t六" );
			
			for( int i = 1; i < pre; i++ ){
				System.out.print("\t");
			}
			for( int i = 1; i < 7-pre+2; i++ ){
				System.out.print(i + "\t");
			}
			System.out.print("\n");
			
			int j = 0;
			for( int i = 7-pre+2; i <= max; i++ ){
				System.out.print( i + "\t" );
				j++;
				if( j == 7 ){
					System.out.println("");
					j = 0;
				}
			}
		} catch (Exception e){
			e.printStackTrace();
		}
	}
}
