#define F(i, a, b) for(int i = a; i <= b; i++)
#define FB(i, a, b) for(int i = a; i >= b; i--)
#define MAX2(a, b) a>b?a:b
#define MIN2(a, b) a<b?a:b

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = s.size();

		if( len < 2 ){
			if( len < 1 ){
				return 0;
			}else{
				return 1;
			}
		}

		int maxLen = 0;
		unordered_set<char> set;

		int i = 1;
		set.insert(s[i-1]);
		int begin = i-1;
		int tmpLen = 1;

		F( i, 2, len ){
			if( set.find( s[i-1] ) == set.end() ){
				//not repeating
				set.insert(s[i-1]);
				tmpLen++;
			}else{
				//repeating
				while( begin < i-1 ){
					if( s[begin] == s[i-1] ){
						begin++;
						break;
					}else{
						set.erase(set.find(s[begin]));
						tmpLen--;
						begin++;
					}
				}
			}
			maxLen = MAX2( maxLen, tmpLen);
		}

		return maxLen;
	}
};
