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

class FormatAmt{
public:
	//2,000,000,000
	string amount(int dollars, int cents){
		vector<char> ret;

		if( cents > 9 ){
			ret.insert(ret.begin(), cents % 10 + '0');
			cents /= 10;
			ret.insert(ret.begin(), cents + '0');
		}else{
			ret.insert(ret.begin(), cents + '0');
			ret.insert(ret.begin(), '0');
		}
		ret.insert(ret.begin(), '.');

		int cnt = 1;
		do{
			if( (cnt+1) % 3 == 0 ){
				ret.insert(ret.begin(), ',');
			}
			cnt++;
			ret.insert(ret.begin(), dollars % 10 + '0');
			dollars /= 10;
		}while( dollars > 0 );
		ret.insert(ret.begin(), '$');

		return string(ret.begin(), ret.end());
	}
};
