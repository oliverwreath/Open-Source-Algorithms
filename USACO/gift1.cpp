/*
ID: skywalk10
PROG: gift1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
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

int main() {
	ofstream fout ("gift1.out");
	ifstream fin ("gift1.in");
	int n;
	fin >> n;
	unordered_map<string, int> ht;
	vector<string> list;
	for( int i = 0; i < n; i++ ){
		string tmp;
		fin >> tmp;
		ht[tmp] = 0;
		list.push_back(tmp);
	}

	string tmp;
	while( fin >> tmp ){
		if( ht.find(tmp) == ht.end() ){
			break;
		}
		int amount, portions;
		fin >> amount >> portions;
		if( amount != 0 ){
			if( portions == 0 ){
				ht[tmp] -= amount;
			}else{
				int one_portion = amount / portions;
				int remaining = amount - one_portion * portions;
				ht[tmp] = ht[tmp] + remaining - amount;
				for( int i = 0; i < portions; i++ ){
					fin >> tmp;
					ht[tmp] += one_portion;
				}
			}
		}
	}

	for( int i = 0; i < n; i++ ){
		fout << list[i] << " " << ht[list[i]] << endl;
	}

	return 0;
}
