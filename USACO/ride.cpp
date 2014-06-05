/*
ID: skywalk10
PROG: ride
LANG: C++11
*/
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
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <list>
#include <deque>

using namespace std;

const string GO = "GO";
const string STAY = "STAY";
const int MODDER = 47;

int main() {
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");
	string a, b;
	while( fin >> a >> b ){
		int aa = 1, bb = 1;
		for( auto ch : a ){
			aa *= ch - 'A' + 1;
		}
		for( auto ch : b ){
			bb *= ch - 'A' + 1;
		}
		aa %= MODDER;
		bb %= MODDER;

		if( aa == bb ){
			fout << GO << endl;
		}else{
			fout << STAY << endl;
		}
	}

	return 0;
}
