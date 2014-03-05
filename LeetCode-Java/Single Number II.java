



public class Solution { 
	public int singleNumber(int[] A){ 
		Set<Integer> set = new HashSet<Integer>(); 

		int len = A.length; 
		long sum = 0; 
		for( int i = 0 ; i <= len-1 ; i++ ){ 
			set.add(A[i]); 
			sum += A[i]; 
		} 

		long setsum = 0;
		for( int i : set ){
			setsum += i;
		}

		long ret = (setsum - sum + setsum * 2)/2; 

		return (int)ret; 
	}
}



