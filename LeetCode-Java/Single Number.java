
public class Solution { 
	public int singleNumber(int[] A){ 
		Set<Integer> set = new HashSet<Integer>(); 

		int len = A.length; 
		int sum = 0; 
		for( int i = 0 ; i <= len-1 ; i++ ){ 
			set.add(A[i]); 
			sum += A[i]; 
		} 

		int setsum = 0;
		for( int i : set ){
			setsum += i;
		}

		int ret = setsum * 2 - sum; 

		return ret; 
	}
}


