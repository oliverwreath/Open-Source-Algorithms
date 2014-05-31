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

class SymbolFrequency{
public:
	double getDev(string fre, vector<string> text){
		double* fr = new double [26]();
		int idx = 0;
		int len = fre.size();

		double* txtfr = new double [26]();
		int cnt = 0;
		for( auto it = text.begin(); it != text.end(); it++ ){
			for( auto itt = (*it).begin(); itt != (*it).end(); itt++ ){
				if( (*itt) != ' ' ){
					txtfr[(*itt)-'a']++;
					cnt++;
				}
			}
		}

		while( idx < len ){
			int tmp;
			sscanf( fre.substr(idx+1, 2).c_str(), "%d", &tmp );
			fr[fre[idx] - 'a'] = tmp * cnt / 100.0;
			idx += 3;
		}

		for( auto i = 0; i < 26; i++ ){
			cout << i << " txt: " << txtfr[i] << " fr: " << fr[i] << endl;
		}

		double sum = 0.0;
		for( auto i = 0; i < 26; i++ ){
			sum += pow((txtfr[i] - fr[i]), 2);
		}

		delete [] txtfr;
		delete [] fr;
		return sum;
	}

	double language(vector<string> frequencies, vector<string> text){
		double minSum = LDBL_MAX;

		for( auto it = frequencies.begin(); it != frequencies.end(); it++ ){
			double sum = getDev((*it), text);
			if( minSum > sum )
				minSum = sum;
		}

		return minSum;
	}

};
