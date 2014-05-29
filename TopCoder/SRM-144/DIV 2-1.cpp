#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
//#include <stdlib.h>

using namespace std;

// 5436
// Returns: "1:30:36"

class Time{
public:
	string whatTime(int seconds){
		int h = seconds / 3600;
		seconds %= 3600;
		int m = seconds / 60;
		seconds %= 60;
		int s = seconds;

		return to_string(h) +":"+ to_string(m) +":"+ to_string(s);
	}
};
