#define F(i, a, b) for(int i = a; i <= b; i++)
#include <vector>
#include <unordered_set>

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if( s == NULL ){
            return 0;
        }
        int i = 0;
        int sum = 0;
        int max = 0;

        while( s[i] != '\0' ){
            if( s[i] != ' ' ){
                sum++;
                max = sum;
            }
            else{
                sum = 0;
            }
            i++;
        }
        return max;
    }
};
