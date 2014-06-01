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

using namespace std;

int main(){
	int n;
	vector<vector<int>> data;
	cin >> n;
	for( int i = 0; i < n; i++ ){
		vector<int> tmp;
		for( int j = 0; j < n; j++ ){
			int tmpint;
			cin >> tmpint;
			tmp.push_back(tmpint);
		}
		data.push_back(tmp);
	}

	for( int mark = 0; mark < n; mark++ ){
		for( int i = mark, j = 0; j <= mark; i--, j++ ){
			cout << data[i][j] << endl;
		}
	}

	for( int mark = 1; mark < n; mark++ ){
		for( int i = n-1, j = mark; j <= n-1; i--, j++ ){
			cout << data[i][j] << endl;
		}
	}

	return 0;
}
