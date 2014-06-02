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
#include <set>

using namespace std;

//class Ural{
//	set<unsigned int> dp;
//	const unsigned int LENGTH_OF_DP = 2147483647;
//
//public:
//	void init(){
//		unsigned int i = 1, step = 1;
//		while( i < LENGTH_OF_DP ){
//			dp.insert(i);
//			i += step;
//			step++;
//		}
//
//		return;
//	}
//
//	int get110100(int n){
//		return (dp.find(n)==dp.end()?0:1);
//	}
//};

int main(){
	int n;
//	Ural t = Ural();
	cin >> n;
	vector<int> lineData = vector<int>(n, 0);
	vector<vector<int>> data = vector<vector<int>>(n, lineData);

	int cnt = 1, num_of_steps = 0;
	for( int mark = n-1; mark >= 0; mark-- ){
		int i = 0, j = mark;
		int steps_to_go = num_of_steps++;
		data[i][j] = cnt++;
		while( steps_to_go-- > 0 ){
			i++;
			j++;
			data[i][j] = cnt++;
		}
	}
	num_of_steps -= 2;
	for( int mark = 1; mark < n; mark++ ){
		int i = mark, j = 0;
		int steps_to_go = num_of_steps--;
		data[i][j] = cnt++;
		while( steps_to_go-- > 0 ){
			i++;
			j++;
			data[i][j] = cnt++;
		}
	}

	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < n; j++ ){
			cout << data[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
