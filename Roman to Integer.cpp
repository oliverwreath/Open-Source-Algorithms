#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#include <vector>
#include <unordered_map>

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();

        if( n == 0 ){
            return 0;
        }
        unordered_map<char, int> ht;
        ht['I'] = 1;
        ht['V'] = 5;
        ht['X'] = 10;
        ht['L'] = 50;
        ht['C'] = 100;
        ht['D'] = 500;
        ht['M'] = 1000;

        int sum = ht[s[n-1]];
        FB( i, n-2, 0 ){
            if( ht[s[i]] >= ht[s[i+1]] ){
                sum += ht[s[i]];
            }else{
                sum -= ht[s[i]];
            }
        }

        return sum;
    }
};
