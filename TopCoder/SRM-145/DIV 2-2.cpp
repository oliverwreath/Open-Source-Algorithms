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

class ExerciseMachine{
public:
	int getPercentages(string time){
		int h, m, s;
		sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);

		s = h * 3600 + m * 60 + s;
		int cnt = 0;
		for( auto i = 1; i < 100; i++ ){
			if( i * s % 100 == 0 ){
				cnt ++;
			}
		}

		return cnt; 
	}
};
