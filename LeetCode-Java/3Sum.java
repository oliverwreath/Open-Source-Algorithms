



public class Solution {
	public ArrayList<ArrayList<Integer>> threeSum(int[] num) {
		int len = num.length; 
		if( len < 3 ){
			return new ArrayList<ArrayList<Integer>>();
		}

		Arrays.sort( num );

		ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
		ArrayList<Integer> list = new ArrayList<Integer>();
		int sum = 0;
		for( int i = 0; i <= len -3; i++ ){
			if( i > 0 && num[i] == num[i-1] ) continue; 
			sum += num[i];
			for( int j = i+1; j <= len -2; j++ ){
				if( j > i+1 && num[j] == num[j-1] ) continue; 
				sum += num[j];
				for( int k = j+1; k <= len -1; k++ ){
					if( k > j+1 && num[k] == num[k-1] ) continue; 
					sum += num[k];
					if( sum > 0 ){
						sum -= num[k];
						break;
					}
					if( sum == 0 ){
						list.add( num[i] );
						list.add( num[j] );
						list.add( num[k] );
						ret.add( (ArrayList<Integer>)list.clone() );
						list.clear();
					}
					sum -= num[k];
				}
				sum -= num[j];
			}
			sum -= num[i];
		}

		return ret; 
	}
}



