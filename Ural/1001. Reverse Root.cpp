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
	long long a;
	stack<long long> data;
	while(cin >> a){
		data.push(a);
	}
	cout.precision(4);
	while( !data.empty() ){
		cout << fixed << sqrt(data.top()) << endl;
		data.pop();
	}
	return 0;
}
