import java.util.Hashtable; 

public class Solution { 
	public int[] twoSum(int[] numbers, int target){ 
		int [] res = new int [2];
		int len = numbers.length; 
		Hashtable<Integer, Integer> ht = new Hashtable<Integer, Integer>();
		for( int i = 0; i < len; i++ ){
			Integer nn = ht.get(numbers[i]);
			if( nn == null ){
				Integer remainingIndex = ht.get( target - numbers[i] );
				if( remainingIndex != null ){
					if( i < remainingIndex ){
						res[0] = i+1;
						res[1] = remainingIndex+1;
					}else{
						res[0] = remainingIndex+1;
						res[1] = i+1;
					}
					return res;
				}
				ht.put(numbers[i], i);
			}else{
				if( nn < i && numbers[i] * 2 == target ){
					res[0] = nn+1;
					res[1] = i+1;
					return res;
				}
			}
		}

		return res;
	}
}


