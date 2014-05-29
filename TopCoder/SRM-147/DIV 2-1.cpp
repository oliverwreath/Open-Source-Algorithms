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

class CCipher{
public:
	string decode(string cipherText, int shift){
		int len = cipherText.size();
		if(shift == 0){
			return cipherText;
		}

		for( auto i = 0; i < len; i++ ){
			cipherText[i] = cipherText[i] - 'A' + 26 - shift;
			cipherText[i] %= 26;
			cipherText[i] += 'A';
		}

		return cipherText;
	}
};
