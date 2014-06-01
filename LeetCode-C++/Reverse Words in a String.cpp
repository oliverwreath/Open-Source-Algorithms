#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cfloat>

using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		int len = s.size();
		if( len < 1 ){
			return ;
		}else if( len < 2 ){
			if( s == " " ) s = "";
			return ;
		}

		int i = 0, j = len-1;
		while(s[i] == ' ' && i < len){
			i++;
		}
		while(s[j] == ' ' && -1 < j){
			j--;
		}
		if( i > j ){
			s = "";
			return ;
		}
		s = s.substr(i, j-i+1);
		len = s.size();
		for( i = 1, j = 1; j < len; ){
			while( s[j] == ' ' && s[j-1] == ' ' ){
				j++;
				if( j >= len ){
					break;
				}
			}
			s[i] = s[j];

			i++;
			j++;
		}
		s.resize(i);
		reverse(s.begin(), s.end());

		len = s.size();
		for( i = 0; i < len; i++ ){
			if( s[i] != ' ' ){
				j = i + 1;
				while( j < len && s[j] != ' ' ){
					j++;
				}
				reverse(&s[i], &s[j]);
				i = j;
			}
		}

		return ;
	}
};
