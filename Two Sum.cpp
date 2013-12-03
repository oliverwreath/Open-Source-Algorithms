class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        int len = numbers.size(); 
        for( int i = 0; i <= len- 1; i++ ){
            for( int j = i+1; j <= len-1; j++ ){
                if( numbers[i] + numbers[j] == target ){
                    ret.push_back( i+1 );
                    ret.push_back( j+1 );
                }
            }
        }
        return ret; 
    }
};
