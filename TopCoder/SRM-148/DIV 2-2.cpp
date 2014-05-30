#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <cstdio>
#include <cstring>

using namespace std;

class CeyKaps{
public:
	string decipher(string typed, vector<string> switches){
		int* codes = new int [26]();
		int* poss = new int [26]();
		for( auto i = 0; i < 26; i++ ){
			codes[i] = i;
			poss[i] = i;
		}

		for( auto it = switches.begin(); it != switches.end(); it++ ){
			char f, t;
			sscanf( (*it).c_str(), "%c:%c", &f, &t );
			int tmp = poss[f-'A'];
			poss[f-'A'] = poss[t-'A'];
			poss[t-'A'] = tmp;
			tmp = codes[poss[f-'A']];
			codes[poss[f-'A']] = codes[poss[t-'A']];
			codes[poss[t-'A']] = tmp;
		}

		string ret = typed;
		int len = typed.size();
		for( auto i = 0; i < len; i++ ){
			ret[i] = codes[typed[i]-'A']+'A';
		}

		return ret;
	}
};
