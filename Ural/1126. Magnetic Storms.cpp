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
#include <list>
#include <deque>

using namespace std;

class Data{
public:
	Data(int id, int value){
		this->id = id;
		this->value = value;
	}
	int id;
	int value;
};

int main(){
	int m;
	cin >> m;
	int num;
	int cnt = 0;
	deque<Data> dq;
	while( cin >> num ){
		if( num == -1 ){
			return 0;
		}

		cnt++;
		while( !dq.empty() && dq.back().value <= num ){
			dq.pop_back();
		}
		dq.push_back(Data(cnt, num));

		if(cnt >= m){
			//output maxima
			while( !dq.empty() && dq.front().id <= (cnt-m) ){
				dq.pop_front();
			}
			cout << dq.front().value << endl;
		}
	}

	return 0;
}
