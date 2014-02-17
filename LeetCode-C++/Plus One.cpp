class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();

        if( len == 0 ){
            digits[0] = 1;
            return digits;
        }

        int i;
        for( i = len-1; i >= 0; i-- ){
            if( digits[i] == 9 ){
                digits[i] = 0;
            }else{
                digits[i]++;
                return digits;
            }
        }

        if(i < 0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
