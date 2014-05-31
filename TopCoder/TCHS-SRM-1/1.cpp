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

class SpeedRadar{
public:
	double averageSpeed(int minLimit, int maxLimit, vector<int> readings){
		int len = readings.size();
		if( len < 1 ){
			return 0.0;
		}

		int cnt = 0, sum = 0;
		for( auto it = readings.begin(); it != readings.end(); it++ ){
			if( (*it) < minLimit || (*it) > maxLimit ){
				cnt++;
			}else{
				sum += (*it);
			}
		}

		if( cnt * 100 > len * 10 ){
			return 0.0;
		}else{
			return (long double)sum / (len - cnt);
		}

	}
};
