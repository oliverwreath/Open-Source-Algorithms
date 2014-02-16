#define F(i, a, b) for(int i = a; i <= b; i++)
#define FF(i, a, b) for( i = a; i <= b; i++)
#define F3(i, a, b) for(int i = a; i <= b; i+=3)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MAX3( a, b, c ) a>b?(a>c?a:c):(b>c?b:c)
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <unordered_set>
#include <tuple>
#include <iterator>
#include <stack>

class Solution {
public:
	bool isPalindrome(string s) {
		int len = s.size();

		if( len == 0 ){
			return true;
		}

		int i = 0;
		int j = len-1;
		while( i < j ){
			if( s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z' ){
				i++;
				continue;
			}
			if( s[j] < '0' || (s[j] > '9' && s[j] < 'A') || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z' ){
				j--;
				continue;
			}

			if( s[i] > '9' ){
				//alpha
				int tmp = s[i]-s[j];
				tmp = tmp>=0?tmp:-tmp;
				if( tmp == 0 || tmp == 32 ){
					i++;
					j--;
					continue;
				}else{
					return false;
				}
			}else{
				//numeric
				if( s[i] == s[j] ){
					i++;
					j--;
					continue;
				}else{
					return false;
				}
			}
		}

		return true;
	}
};
