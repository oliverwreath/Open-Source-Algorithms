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

class YahtzeeScore{
public:
	int maxPoints(vector<int> toss){
		int len = toss.size();

		int* res = new int [7]();

		for( auto i = 0; i < len; i++ ){
			res[toss[i]] += toss[i];
		}
		int max = 0;

		for( auto i = 1; i <= 6; i++ ){
			if( res[i] > max ){
				max = res[i];
			}
		}
		return max; 
	}
};
