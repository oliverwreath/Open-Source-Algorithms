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
	string longestCommonPrefix(vector<string> &strs) {
		int n = strs.size();
		if( n == 0 ){
			return string();
		}
		if( n < 2 ){
			return strs[0];
		}

		bool flag = true;
		int len = 0;
		int index = 0;
		while( flag ){
			if( strs[0].size() <= index ){
				break;
			}

			F( i, 1, n-1 ){
				if( strs[i].size() <= index || strs[i][index] != strs[0][index] ){
					flag = false;
					break;
				}
			}

			if( flag ){
				len++;
			}else{
				break;
			}
			index++; 
		}

		return strs[0].substr(0, len);
	}
};
