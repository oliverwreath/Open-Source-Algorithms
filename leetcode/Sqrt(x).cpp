class Solution {
public:
    int sqrt( const int x ) {
		int max = 65536;

        for( long long i = 0; i <= max; i++ ){
			long long tmp = i*i;
            if( tmp == x){
                return i;
            }
			else if( tmp > x ){
				return i-1;
			}
        }

		return -1;
    }
};
