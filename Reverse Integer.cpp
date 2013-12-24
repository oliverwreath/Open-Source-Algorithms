#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Solution {
public:
    int reverse(long long x){
        int neg = 1;
        if( x < 0 ){
            neg = -1;
            x = -x;
        }

        long long ret = 0;
        while( x > 0 ){
        	ret *= 10;
        	ret += x % 10;
        	x /= 10;
        }
        ret *= neg;

        if( neg == 1 ){
        	if( ret > INT_MAX ){
        		return INT_MAX;
        	}else{
        		return ret;
        	}
        }else{
        	if( ret < INT_MIN ){
        		return INT_MIN;
        	}else{
        		return ret;
        	}
        }
    }
};
