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
    int atoi(const char *str) {
        if( str == NULL ){
            return 0;
        }

        if( str[0] == '\0' ){
            return 0;
        }

        long long neg;
        int i = 0;
        while( str[i] == ' ' ){
            i++;
        }

        if( str[i] == '-' ){
            neg = -1;
            i++;
        }else if( str[i] == '+' ){
            neg = 1;
            i++;
        }else{
            neg = 1;
        }

        long long ret = 0;
        while( str[i] != '\0' ){
            if( str[i] > 47 && str[i] < 58 ){
                ret *= 10;
                ret += (str[i]-48);
                i++;
            }else{
                break; 
            }
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
