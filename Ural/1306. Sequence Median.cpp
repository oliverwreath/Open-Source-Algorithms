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

const long double LDBL2 = 2.0;
const double DBL2 = 2.0;
const int LENGTH = 250000;

int main(){
	int n;
	while( cin >> n ){
		unsigned int tmp;
		priority_queue<unsigned int> pq;
		for( int i = 0; i <= n/2; i++ ){
			cin >> tmp;
			pq.push(tmp);
		}

		for( int i = n/2+1; i < n; i++){
			cin >> tmp;
			if( tmp < pq.top() ){
				pq.pop();
				pq.push(tmp);
			}
		}

		if( (n&1) == 1 ){
			//odd
			cout << pq.top() << endl;
		}else{
			unsigned int a = pq.top();
			pq.pop();
			unsigned int b = pq.top();
			int remaining = (a&1) + (b&1);
			if( remaining == 2 ){
				cout << a/2 + b/2 + 1 << endl;
			}else if( remaining == 1 ){
				cout << a/2 + b/2 << ".5" << endl;
			}else{
				cout << a/2 + b/2 << endl;
			}
		}
	}

	return 0;
}


