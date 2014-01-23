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
#include <unordered_map>
#include <tuple>
#include <iterator>
#include <stack>
#include <algorithms>

class Solution {
public:
	vector<string> letterCombinations(string digits) {	
		int len = digits.size();
		if( len < 1 ){
			return vector<string>(1, ""); 
		}

		vector<vector<string>> table; 
		vector<string> tmp = {"a", "b", "c"};
		tmp = {"a", "b", "c"};
		table.push_back(tmp); 
		table.push_back(tmp);
		table.push_back(tmp);
		tmp = {"d", "e", "f"};
		table.push_back(tmp);
		tmp = {"g", "h", "i"};
		table.push_back(tmp);
		tmp = {"j", "k", "l"};
		table.push_back(tmp);
		tmp = {"m", "n", "o"};
		table.push_back(tmp);
		tmp = {"p", "q", "r", "s"};
		table.push_back(tmp);
		tmp = {"t", "u", "v"};
		table.push_back(tmp);
		tmp = {"w", "x", "y", "z"};
		table.push_back(tmp);
		string res; 
		vector<string> ret; 

		ret = table[digits[0]-'0'];
		F( i, 1, len-1 ){
			int retlen = ret.size();
			F(j, 0, retlen-1){
				string tmpp = ret[0];
				ret.erase(ret.begin());
				int newLen = table[digits[i]-'0'].size();
				F(k, 0, newLen-1){
					ret.push_back(tmpp + table[digits[i]-'0'][k]);
				}
			}
		}

		return ret; 
	}
};
