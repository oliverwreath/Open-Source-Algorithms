#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <unordered_set>
//#include <stdlib.h>

using namespace std;

class ImageDithering{
public:
	int count(string dithered, vector<string> screen){
		unordered_set<char> target;
		int len = dithered.size();
		for( auto i = 0; i < len; i++ ){
			target.insert(dithered[i]);
		}

		int cnt = 0;
		for( auto it = screen.begin(); it != screen.end(); it++ ){
			int len = (*it).size();
			for( auto i = 0; i < len; i++ ){
				if(target.find((*it)[i]) != target.end()){
					cnt++;
				}
			}
		}

		return cnt;
	}
};
